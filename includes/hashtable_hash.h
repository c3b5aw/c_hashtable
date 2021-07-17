/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_hash.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:40 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/17 22:28:38 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_HASH_H
# define HASHTABLE_HASH_H

# define HASH_SIZE	65536

unsigned long	__hashtable_hash_function(char *key);

#endif