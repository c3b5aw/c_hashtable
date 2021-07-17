/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:40:03 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 00:53:17 by c3b5aw           ###   ########.fr       */
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

void	show_data(void *data)
{
	t_hashtable_item	*item;

	item = (t_hashtable_item *)data;
	printf("[%s] = %s\n", item->key, (char *)item->value);
}

bool	test_destroy(t_hashtable **hashtable, char *test_name)
{
	hashtable_iter(*hashtable, show_data);
	hashtable_destroy(hashtable, true);
	if (*hashtable != 0)
	{
		printf("[!] %s: FAILURE\n", test_name);
		return (false);
	}
	printf("[+] %s: SUCCESS\n\n", test_name);
	return (true);
}
