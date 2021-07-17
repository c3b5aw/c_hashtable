/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable__private_methods.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:36 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/17 22:03:56 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE__PRIVATE_METHODS_H
# define HASHTABLE__PRIVATE_METHODS_H

# include "hashtable_types.h"

t_hashtable_item	*__handle_item_insert( \
	t_hashtable **h, t_hashtable_item *item, unsigned long index);
t_hashtable_item	*__handle_item_insert_collision( \
		t_hashtable_item *item, t_hashtable_item *current_item);

#endif