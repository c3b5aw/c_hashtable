/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __private_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:27 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 01:30:23 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_table.h"
#include "../includes/hashtable_methods.h"
#include "../includes/hashtable_utils.h"
#include "../includes/hashtable_hash.h"

static bool	__handle_table_resize(t_hashtable **table)
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
		t_hashtable **h, t_hashtable_item *item)
{
	if ((*h)->size == (*h)->count)
	{
		if (!__handle_table_resize(h))
			return (0);
		return (__handle_item_insert(h, item, __hashtable_hash_function(\
			(*h)->size, item->key)));
	}
	return (0);
}

t_hashtable_item	*__handle_item_insert_collision( \
		t_hashtable **h, t_hashtable_item *item, \
		t_hashtable_item *current_item)
{
	t_hashtable_item	*ret;

	if (__strcmp(item->key, current_item->key) != 0)
	{
		ret = __handle__collision(h, item);
		if (ret)
			return (ret);
	}
	free(current_item->value);
	current_item->value = item->value;
	free(item->key);
	free(item);
	return (current_item);
}
