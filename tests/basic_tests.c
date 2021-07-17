/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:37:38 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 00:07:02 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

bool	create_and_destroy_test(void)
{
	t_hashtable	*hashtable;

	hashtable = 0;
	if (!test_init(&hashtable, 5, "CREATE_AND_DESTROY_TEST"))
		return (false);
	if (!test_destroy(&hashtable, "CREATE_AND_DESTROY_TEST"))
		return (false);
	return (true);
}

bool	insert_one_test(void)
{
	t_hashtable			*hashtable;
	t_hashtable_item	*item;
	char				*name1;
	char				*name2;

	hashtable = 0;
	name1 = strdup("NAME_1");
	name2 = strdup("NAME_2");
	if (!test_init(&hashtable, 5, "INSERT_ONE_TEST"))
		return (false);
	item = hashtable_insert(&hashtable, name1, 0);
	printf("key: %s\n", item->key);
	item = hashtable_insert(&hashtable, name2, 0);
	printf("key: %s\n", item->key);
	if (!test_destroy(&hashtable, "INSERT_ONE_TEST"))
		return (false);
	return (true);
}

int	basic_tests(void)
{
	if (!create_and_destroy_test())
		return (false);
	if (!insert_one_test())
		return (false);
	return (true);
}
