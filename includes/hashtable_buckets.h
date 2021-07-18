/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_buckets.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 05:47:35 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 06:48:21 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_BUCKETS_H
# define HASHTABLE_BUCKETS_H

# include "hashtable_types.h"

t_hashtable_bucket	**hashtable_buckets_init(t_hashtable *hashtable);
void				hashtable_buckets_destroy( \
	t_hashtable *hashtable, bool dealloc_item);
void				hashtable_buckets_remove(t_hashtable_bucket	*root);

#endif