/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:46:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/18 07:27:09 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_utils.h"
#include "../includes/hashtable_table.h"
#include "../includes/hashtable_hash.h"
#include "../includes/hashtable_bucket_methods.h"

t_hashtable_item	*hashtable_item_create(char *key, void *value)
{
	t_hashtable_item	*item;

	item = (t_hashtable_item *)malloc(sizeof(t_hashtable_item));
	if (!item)
		return (0);
	item->key = key;
	item->value = value;
	return (item);
}

void	hashtable_item_destroy(t_hashtable_item *item, bool dealloc_value)
{
	if (!item)
		return ;
	free(item->key);
	if (dealloc_value)
		free(item->value);
	free(item);
}

void	hashtable_item_remove(t_hashtable *h, t_hashtable_item *item)
{
	t_hashtable_item	*_item;
	t_hashtable_bucket	*bucket;
	unsigned long		index;

	if (!h || !item)
		return ;
	index = __hashtable_hash_function(h->size, item->key);
	_item = h->items[index];
	bucket = h->buckets[index];
	if (!bucket && __strcmp(item->key, _item->key) == 0)
	{
		h->items[index] = 0;
		hashtable_item_destroy(_item, true);
		--h->count;
		return ;
	}
	if (bucket)
	{
		if (__strcmp(item->key, _item->key) == 0)
			return (__handle_collision_chain_remove_head(\
				h, item, bucket, index));
		return (__handle_collision_chain_remove_iter(\
			h, item, bucket, index));
	}
}

t_hashtable_item	*hashtable_item_copy( \
	t_hashtable **dst, t_hashtable_item *item)
{
	if (!item || !*dst)
		return (0);
	return (hashtable_insert(dst, __strdup(item->key), item->value));
}

void	*hashtable_item_get(t_hashtable *hashtable, char *key, bool value)
{
	t_hashtable_item	*item;
	t_hashtable_bucket	*bucket;
	unsigned long		index;

	index = __hashtable_hash_function(hashtable->size, key);
	item = hashtable->items[index];
	bucket = hashtable->buckets[index];
	while (item)
	{
		if (__strcmp(item->key, key) == 0)
		{
			if (value)
				return (item->value);
			return (item);
		}
		if (!bucket)
			return (0);
		item = bucket->item;
		bucket = bucket->next;
	}
	return (0);
}
