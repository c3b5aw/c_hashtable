/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:37:38 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 04:54:24 by c3b5aw           ###   ########.fr       */
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

	hashtable = 0;
	if (!test_init(&hashtable, 5, "INSERT_ONE_TEST"))
		return (false);
	hashtable_insert(&hashtable, strdup("NAME_5"), 0);
	if (!test_destroy(&hashtable, "INSERT_ONE_TEST"))
		return (false);
	return (true);
}

bool	insert_max_test(void)
{
	t_hashtable			*hashtable;

	hashtable = 0;
	if (!test_init(&hashtable, 5, "INSERT_MAX_TEST"))
		return (false);
	hashtable_insert(&hashtable, strdup("NAME_1"), strdup("NAME_1"));
	hashtable_insert(&hashtable, strdup("NAME_2"), strdup("NAME_2"));
	hashtable_insert(&hashtable, strdup("NAME_3"), strdup("NAME_3"));
	hashtable_insert(&hashtable, strdup("NAME_4"), strdup("NAME_4"));
	hashtable_insert(&hashtable, strdup("NAME_5"), strdup("NAME_5"));
	if (!test_destroy(&hashtable, "INSERT_MAX_TEST"))
		return (false);
	return (true);
}

bool	insert_more_test(void)
{
	t_hashtable			*hashtable;

	hashtable = 0;
	if (!test_init(&hashtable, 5, "INSERT_MORE_TEST"))
		return (false);
	hashtable_insert(&hashtable, strdup("NAME_1"), strdup("NAME_1"));
	hashtable_insert(&hashtable, strdup("NAME_2"), strdup("NAME_2"));
	hashtable_insert(&hashtable, strdup("NAME_3"), strdup("NAME_3"));
	hashtable_insert(&hashtable, strdup("NAME_4"), strdup("NAME_4"));
	hashtable_insert(&hashtable, strdup("NAME_5"), strdup("NAME_5"));
	hashtable_insert(&hashtable, strdup("NAME_6"), strdup("NAME_6"));
	if (!test_destroy(&hashtable, "INSERT_MORE_TEST"))
		return (false);
	return (true);
}

bool	basic_tests(void)
{
	if (!create_and_destroy_test())
		return (false);
	if (!insert_one_test())
		return (false);
	if (!insert_max_test())
		return (false);
	if (!insert_more_test())
		return (false);
	return (true);
}
