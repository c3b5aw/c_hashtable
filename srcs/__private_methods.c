/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __private_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:27 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 00:08:34 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_table.h"

static bool	__handle_table_resize(t_hashtable **table)
{
	t_hashtable	*new_table;

	new_table = hashtable_new((*table)->size * 2);
	return (true);
}

t_hashtable_item	*__handle_item_insert( \
	t_hashtable **h, t_hashtable_item *item, unsigned long index)
{
	if ((*h)->count == (*h)->size)
		if (!__handle_table_resize(h))
			return (0);
	(*h)->items[index] = item;
	++(*h)->count;
	return (item);
}

t_hashtable_item	*__handle_item_insert_collision( \
		t_hashtable_item *item, t_hashtable_item *current_item)
{
	free(current_item->value);
	current_item->value = item->value;
	free(item->key);
	free(item);
	return (current_item);
}
