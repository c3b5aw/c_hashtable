/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 06:02:03 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 09:07:54 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_types.h"
#include "../includes/hashtable_bucket_methods.h"

t_hashtable_bucket	**hashtable_buckets_init(t_hashtable *hashtable)
{
	t_hashtable_bucket	**buckets;
	unsigned int		i;

	buckets = (t_hashtable_bucket **)malloc(\
		sizeof(t_hashtable_bucket *) * hashtable->size);
	if (!buckets)
		return (0);
	i = -1;
	while (++i < hashtable->size)
		buckets[i] = 0;
	return (buckets);
}

void	hashtable_buckets_destroy(t_hashtable *hashtable, bool dealloc_item)
{
	unsigned int		i;

	i = -1;
	while (++i < hashtable->size)
		if (hashtable->buckets[i])
			hashtable_bucket_delete(hashtable->buckets[i], dealloc_item);
	free(hashtable->buckets);
	hashtable->buckets = 0;
}

void	hashtable_buckets_remove(t_hashtable_bucket	*root)
{
	t_hashtable_bucket	*save;

	if (!root)
		return ;
	while (root)
	{
		save = root;
		root = root->next;
		hashtable_bucket_delete(save, true);
		free(save);
	}
}
