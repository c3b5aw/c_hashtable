/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_table.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:05:47 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 00:50:44 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_TABLE_H
# define HASHTABLE_TABLE_H

# include "hashtable_types.h"

t_hashtable	*hashtable_new(unsigned int size);
void		hashtable_destroy(t_hashtable **table, bool dealloc_value);
bool		hashtable_copy(t_hashtable **src, t_hashtable **dst);
void		hashtable_iter(t_hashtable *h, void (*f)(void *));

#endif