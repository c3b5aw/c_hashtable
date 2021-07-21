/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 05:47:25 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/21 17:36:15 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_utils.h"
#include "../includes/hashtable_item.h"
#include "../includes/hashtable_table.h"

t_hashtable_bucket	*hashtable_bucket_new(t_hashtable_item *item)
{
	t_hashtable_bucket	*bucket;

	bucket = (t_hashtable_bucket *)malloc(sizeof(t_hashtable_bucket));
	if (!bucket)
		return (0);
	bucket->next = 0;
	bucket->item = item;
	return (bucket);
}

void	hashtable_bucket_delete(t_hashtable_bucket *bucket, bool dealloc_item)
{
	t_hashtable_bucket	*last;

	if (!bucket)
		return ;
	while (bucket)
	{
		hashtable_item_destroy(bucket->item, dealloc_item);
		last = bucket;
		bucket = bucket->next;
		free(last);
	}
}

t_hashtable_bucket	*hashtable_bucket_insert( \
	t_hashtable_bucket *bucket, t_hashtable_item *item)
{
	t_hashtable_bucket	*node;
	t_hashtable_bucket	*save;

	if (!bucket)
		return (hashtable_bucket_new(item));
	else if (!bucket->next)
	{
		node = hashtable_bucket_new(item);
		if (!node)
			return (0);
		bucket->next = node;
		return (bucket);
	}
	save = bucket;
	while (save->next)
		save = save->next;
	node = hashtable_bucket_new(item);
	if (!node)
		return (0);
	save->next = node;
	return (bucket);
}
