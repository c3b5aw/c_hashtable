/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:26:49 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/17 22:27:24 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_METHODS_H
# define HASHTABLE_METHODS_H

# include "hashtable_types.h"

t_hashtable_item	*hashtable_insert(t_hashtable **h, char *key, void *value);

#endif