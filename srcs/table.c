/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:20 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 08:50:53 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_hash.h"
#include "../includes/hashtable_handler.h"
#include "../includes/hashtable_buckets.h"
#include "../includes/hashtable_bucket_methods.h"
#include "../includes/hashtable.h"

/**
 * * hashtable_new
 *  
 * Allocate space for a new hashtable object.
 * >	return (NULL) on fail.
 * Allocate space for each hashtable item. 
 * > 	return (NULL) on fail.
 * 
 * @param	size 	(unsigned int)		size of the hashtable
 * 
 * @return			(hashtable_t *)		a new hashtable object
 *
**/
t_hashtable	*hashtable_new(unsigned int size)
{
	t_hashtable		*ret;
	unsigned int	i;

	ret = (t_hashtable *)malloc(sizeof(t_hashtable));
	if (!ret)
		return (0);
	ret->size = size;
	ret->count = 0;
	ret->items = (t_hashtable_item **)malloc(sizeof(t_hashtable_item *) * size);
	if (!ret->items)
	{
		free(ret);
		return (0);
	}
	i = -1;
	while (++i < ret->size)
		ret->items[i] = 0;
	ret->buckets = hashtable_buckets_init(ret);
	if (!ret->buckets)
	{
		hashtable_destroy(&ret, true);
		return (0);
	}
	return (ret);
}

/**
 * * hashtable_destroy
 * 
 * Destroy hashtable by iterating over all elements and freeing them. 
 * 
 * @param table	(t_hashtable *)		The hashtable to destroy
 * 
**/

void	hashtable_destroy(t_hashtable **table, bool dealloc_value)
{
	t_hashtable_item	*item;
	unsigned int		i;

	if (!table || !(*table))
		return ;
	i = -1;
	while (++i < (*table)->size)
	{
		item = (*table)->items[i];
		if (item)
			hashtable_item_destroy(item, dealloc_value);
	}
	hashtable_buckets_destroy(*table, dealloc_value);
	free((*table)->items);
	free((*table));
	*table = 0;
}

/**
 * * hashtable_copy
 * 
 * Iterate over src hashtable elements and copy them to dest.
 * 
 * @param  **src 	(t_hashtable *)	: 		Hashtable to copy from
 * @param  **dst 	(t_hashtable *)	:		Hashtable to copy to
 * 
 * @return 			(bool)			:		success
 */
bool	hashtable_copy(t_hashtable **src, t_hashtable **dst)
{
	t_hashtable_bucket	*bucket;
	unsigned int		i;

	if (!*dst || !*src)
		return (false);
	i = -1;
	while (++i < (*src)->size && i < (*dst)->size)
	{
		if ((*src)->items[i])
			if (!hashtable_item_copy(dst, (*src)->items[i]))
				return (false);
		if ((*src)->buckets[i])
		{
			bucket = (*src)->buckets[i];
			while (bucket && bucket->item)
			{
				if (!hashtable_item_copy(dst, bucket->item))
					return (false);
				bucket = (*src)->buckets[i]->next;
			}
		}
	}
	return (true);
}

/**
 * * hashtable_iter
 * 
 * @param  *h	(t_hashtable *)				 : Hashtable to iter in 
 * @param  f	(f(*f)(t_hashtable_item *))) : function to eval on each item
 * @return None
 */

void	hashtable_iter(t_hashtable *h, void (*f)(t_hashtable_item *))
{
	unsigned int	i;

	if (!h || !f)
		return ;
	i = -1;
	while (++i < h->size)
		if (h->items[i])
			f(h->items[i]);
}

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

	if (!key)
		return (0);
	item = hashtable_item_create(key, value);
	if (!item)
		return (0);
	index = __hashtable_hash_function((*h)->size, key);
	current_item = (*h)->items[index];
	if (!current_item)
		return (__handle_item_insert(h, item, index));
	return (__handle_item_insert_collision(h, item, current_item, index));
}
