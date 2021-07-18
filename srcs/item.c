/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:46:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/18 04:20:16 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_utils.h"
#include "../includes/hashtable_table.h"
#include "../includes/hashtable_hash.h"

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
	unsigned long	index;

	if (!h || !item)
		return ;
	index = __hashtable_hash_function(h->size, item->key);
	if (h->items[index] && __strcmp(item->key, h->items[index]->key) == 0)
		h->items[index] = 0;
	hashtable_item_destroy(item, true);
}

t_hashtable_item	*hashtable_item_copy( \
	t_hashtable **dst, t_hashtable_item *item)
{
	if (!item || !*dst)
		return (0);
	return (hashtable_insert(dst, __strdup(item->key), item->value));
}

void	*hashtable_item_get(t_hashtable *hashtable, char *key)
{
	t_hashtable_item	*ret;
	unsigned long		index;

	index = __hashtable_hash_function(hashtable->size, key);
	ret = hashtable->items[index];
	if (ret)
		if (__strcmp(ret->key, key) == 0)
			return (ret->value);
	return (0);
}
