/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_item.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:42 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 01:57:08 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_ITEM_H
# define HASHTABLE_ITEM_H

# include "hashtable_types.h"

t_hashtable_item	*hashtable_item_create(char *key, void *value);
void				hashtable_item_destroy( \
	t_hashtable_item *item, bool dealloc_value);
t_hashtable_item	*hashtable_item_copy( \
	t_hashtable **dst, t_hashtable_item *item);
void				*hashtable_item_get(t_hashtable *hashtable, char *key);

#endif