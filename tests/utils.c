/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:40:03 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/17 23:51:36 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

bool	test_init(t_hashtable **hashtable, unsigned int size, char *test_name)
{
	printf("[+] %s: INIT\n", test_name);
	(*hashtable) = hashtable_new(size);
	if (!*hashtable)
	{
		printf("[!] %s: FAILURE WHILE INIT\n", test_name);
		return (false);
	}
	return (true);
}

bool	test_destroy(t_hashtable **hashtable, char *test_name)
{
	hashtable_destroy(hashtable);
	if (*hashtable != 0)
	{
		printf("[!] %s: FAILURE\n", test_name);
		return (false);
	}
	printf("[+] %s: SUCCESS\n\n", test_name);
	return (true);
}
