/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:46:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/18 01:16:04 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_utils.h"
#include "../includes/hashtable_methods.h"

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

t_hashtable_item	*hashtable_item_copy( \
	t_hashtable **dst, t_hashtable_item *item)
{
	if (!item || !*dst)
		return (0);
	return (hashtable_insert(dst, __strdup(item->key), item->value));
}
