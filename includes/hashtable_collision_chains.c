/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_collision_chains.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 07:38:47 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 07:43:37 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_COLLISION_CHAINS_H
# define HASHTABLE_COLLISION_CHAINS_H

# include "hashtable_types.h"

void	__handle_collision_chain_remove_head( \
	t_hashtable *hashtable, t_hashtable_item *item, \
	t_hashtable_bucket *bucket, unsigned long index);
void	__handle_collision_chain_remove_iter( \
	t_hashtable *h, t_hashtable_item *item, \
	t_hashtable_bucket *bucket, unsigned long index);

#endif