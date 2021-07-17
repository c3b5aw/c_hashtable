/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:20 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 01:37:29 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_item.h"
#include "../includes/hashtable_types.h"

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
	free((*table)->items);
	free((*table));
	*table = 0;
}

/**
 * @brief  
 * @note   
 * @param  **src 	(t_hashtable *)	: 		Hashtable to copy from
 * @param  **dst 	(t_hashtable *)	:		Hashtable to copy to
 * @retval 			(bool)			:		success
 */
bool	hashtable_copy(t_hashtable **src, t_hashtable **dst)
{
	unsigned int	i;

	if (!*dst || !*src)
		return (false);
	i = -1;
	while (++i < (*src)->size && i < (*dst)->size)
		if ((*src)->items[i])
			if (!hashtable_item_copy(dst, (*src)->items[i]))
				return (false);
	return (true);
}

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
