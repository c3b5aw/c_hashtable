/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:37:38 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 00:13:39 by c3b5aw           ###   ########.fr       */
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
	if (!test_init(&hashtable, 5, "INSERT_ONE_TEST"))
		return (false);
	hashtable_insert(&hashtable, strdup("NAME_1"), 0);
	hashtable_insert(&hashtable, strdup("NAME_2"), 0);
	hashtable_insert(&hashtable, strdup("NAME_3"), 0);
	hashtable_insert(&hashtable, strdup("NAME_4"), 0);
	hashtable_insert(&hashtable, strdup("NAME_5"), 0);
	if (!test_destroy(&hashtable, "INSERT_ONE_TEST"))
		return (false);
	return (true);
}

bool	insert_more_test(void)
{
	t_hashtable			*hashtable;

	hashtable = 0;
	if (!test_init(&hashtable, 5, "INSERT_ONE_TEST"))
		return (false);
	hashtable_insert(&hashtable, strdup("NAME_1"), 0);
	hashtable_insert(&hashtable, strdup("NAME_2"), 0);
	hashtable_insert(&hashtable, strdup("NAME_3"), 0);
	hashtable_insert(&hashtable, strdup("NAME_4"), 0);
	hashtable_insert(&hashtable, strdup("NAME_5"), 0);
	hashtable_insert(&hashtable, strdup("NAME_6"), 0);
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
	if (!insert_max_test())
		return (false);
	if (!insert_more_test())
		return (false);
	return (true);
}
