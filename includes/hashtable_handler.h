/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_handler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:36 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 06:24:53 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_HANDLER_H
# define HASHTABLE_HANDLER_H

# include "hashtable_types.h"

bool				__handle_table_resize(t_hashtable **table);
t_hashtable_item	*__handle_item_insert( \
	t_hashtable **h, t_hashtable_item *item, unsigned long index);
t_hashtable_item	*__handle_item_insert_collision( \
		t_hashtable **h, t_hashtable_item *item, \
		t_hashtable_item *current_item, unsigned long index);

#endif