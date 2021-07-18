/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_chains.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 07:37:28 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 07:44:10 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_utils.h"
#include "../includes/hashtable_item.h"
#include "../includes/hashtable_bucket_methods.h"

void	__handle_collision_chain_remove_head( \
	t_hashtable *hashtable, t_hashtable_item *item, \
	t_hashtable_bucket *bucket, unsigned long index)
{
	t_hashtable_bucket	*node;

	hashtable_item_destroy(item, true);
	node = bucket;
	bucket = bucket->next;
	node->next = 0;
	hashtable->items[index] = hashtable_item_create(\
		node->item->key, node->item->value);
	hashtable_bucket_delete(node, true);
	hashtable->buckets[index] = bucket;
}

static void	__handle_collide_no_prev(
	t_hashtable *h, t_hashtable_bucket *bucket, unsigned long index)
{
	hashtable_bucket_delete(bucket, true);
	h->buckets[index] = 0;
}

void	__handle_collision_chain_remove_iter( \
	t_hashtable *h, t_hashtable_item *item, \
	t_hashtable_bucket *bucket, unsigned long index)
{
	t_hashtable_bucket	*prev;
	t_hashtable_bucket	*cur;

	cur = bucket;
	prev = 0;
	while (cur)
	{
		if (__strcmp(cur->item->key, item->key) == 0)
		{
			if (!prev)
				return (__handle_collide_no_prev(h, bucket, index));
			else
			{
				prev->next = cur->next;
				cur->next = 0;
				hashtable_bucket_delete(bucket, true);
				h->buckets[index] = bucket;
				return ;
			}
		}
		cur = cur->next;
		prev = cur;
	}
}
