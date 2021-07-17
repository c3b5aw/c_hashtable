/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:46:24 by marvin            #+#    #+#             */
/*   Updated: 2021/07/17 22:28:45 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hashtable_hash.h"

unsigned long	__hashtable_hash_function(char *key)
{
	unsigned long	i;
	int				k;

	i = 0;
	k = -1;
	while (key[++k])
		i += key[k];
	return (i % HASH_SIZE);
}
