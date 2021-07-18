/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_bucket_methods.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 06:08:51 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 09:17:22 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_BUCKET_METHODS_H
# define HASHTABLE_BUCKET_METHODS_H

# include "hashtable_types.h"

t_hashtable_bucket	*hashtable_bucket_new(t_hashtable_item *item);
t_hashtable_bucket	*hashtable_bucket_insert( \
	t_hashtable_bucket *bucket, t_hashtable_item *item);
void				hashtable_bucket_delete( \
	t_hashtable_bucket *bucket, bool dealloc_item);
void				__handle_collision_chain_remove_head( \
	t_hashtable *hashtable, t_hashtable_item *item, \
	t_hashtable_bucket *bucket, unsigned long index);
void				__handle_collision_chain_remove_iter( \
	t_hashtable *hashtable, t_hashtable_item *item, \
	t_hashtable_bucket *bucket, unsigned long index);

#endif