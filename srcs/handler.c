/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:27 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 07:31:51 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable.h"
#include "../includes/hashtable_utils.h"
#include "../includes/hashtable_hash.h"
#include "../includes/hashtable_bucket_methods.h"

bool	__handle_table_resize(t_hashtable **table)
{
	t_hashtable	*new_table;

	new_table = hashtable_new((*table)->size * 2);
	if (!hashtable_copy(table, &new_table))
	{
		free(new_table);
		return (false);
	}
	hashtable_destroy(table, false);
	*table = new_table;
	return (true);
}

t_hashtable_item	*__handle_item_insert( \
	t_hashtable **h, t_hashtable_item *item, unsigned long index)
{
	(*h)->items[index] = item;
	++(*h)->count;
	return (item);
}

static t_hashtable_item	*__handle__collision( \
		t_hashtable **h, t_hashtable_item *item, unsigned long index)
{
	t_hashtable_bucket	*bucket;

	bucket = (*h)->buckets[index];
	if (!bucket)
	{
		bucket = hashtable_bucket_new(item);
		if (!bucket)
			return (0);
		(*h)->buckets[index] = bucket;
	}
	else
	{
		(*h)->buckets[index] = hashtable_bucket_insert(bucket, item);
		if (!(*h)->buckets[index])
			return (0);
	}
	(*h)->count++;
	return (item);
}

/**
 * * __handle_item_insert_collision
 * 
 * We have a collision, we have to handle it.
 * If we only need to update the value, keys are matching.
 * Otherwise we try to handle the collision using buckets
 * 
 * @param  **h: 
 * @param  *item: 
 * @param  *current_item: 
 * @param  index: 
 * @return
 */

t_hashtable_item	*__handle_item_insert_collision( \
		t_hashtable **h, t_hashtable_item *item, \
		t_hashtable_item *current_item, unsigned long index)
{
	if (__strcmp(item->key, current_item->key) == 0)
	{
		(*h)->items[index]->value = item->value;
		hashtable_item_destroy(item, false);
		return ((*h)->items[index]);
	}
	return (__handle__collision(h, item, index));
}
