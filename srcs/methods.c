/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:45:44 by marvin            #+#    #+#             */
/*   Updated: 2021/07/17 22:29:30 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_item.h"
#include "../includes/hashtable_hash.h"
#include "../includes/hashtable__private_methods.h"

/**
 * hashtable_insert
 * 
 * * Insert an item in the hashtable
 * 
 * > Create a new item
 * > Compute hash function of new item
 * > Verify for collision with shared hash_key
 * - > If collision, update existing key
 * - > If no collision
 * - - > Verify for sufficent space in hash_table, otherwise extend
 * - - > Insert new item in hashtable
 * 
 * @param	t				Ptr to hashtable
 * 							Will be updated in case we resize hashtable.			
 * @param	key				Item key
 * @param	value			Ptr to the value
 * 
 * @return					The item inserted
**/

t_hashtable_item	*hashtable_insert(t_hashtable **h, char *key, void *value)
{
	t_hashtable_item	*item;
	t_hashtable_item	*current_item;
	unsigned long		index;

	item = hashtable_item_create(key, value);
	if (!item)
		return (false);
	index = __hashtable_hash_function(key);
	current_item = (*h)->items[index];
	if (!current_item)
		return (__handle_item_insert(h, item, index));
	return (__handle_item_insert_collision(item, current_item));
}
