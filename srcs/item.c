/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:46:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/17 21:46:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"

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

void	hashtable_item_destroy(t_hashtable_item *item)
{
	if (!item)
		return ;
	free(item->key);
	free(item->value);
	free(item);
}
