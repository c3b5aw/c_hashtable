/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:44:19 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 02:01:52 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

bool	find_one(void)
{
	t_hashtable	*hashtable;
	void		*value;

	hashtable = 0;
	if (!test_init(&hashtable, 5, FIND_TEST_1))
		return (false);
	hashtable_insert(&hashtable, strdup("NAME_1"), strdup("NAME_1"));
	hashtable_insert(&hashtable, strdup("NAME_2"), strdup("NAME_2"));
	hashtable_insert(&hashtable, strdup("NAME_3"), strdup("NAME_3"));
	hashtable_insert(&hashtable, strdup("NAME_4"), strdup("NAME_4"));
	hashtable_insert(&hashtable, strdup("NAME_5"), strdup("NAME_5"));
	value = hashtable_item_get(hashtable, "NAME_1");
	if (!value)
		return (error(&hashtable, FIND_TEST_1, EXIST_ERR));
	printf("[FOUND]: %s\n", (char *)value);
	if (!test_destroy(&hashtable, FIND_TEST_1))
		return (false);
	return (true);
}

bool	find_no_existing(void)
{
	t_hashtable	*hashtable;
	void		*value;

	hashtable = 0;
	if (!test_init(&hashtable, 5, FIND_TEST_2))
		return (false);
	hashtable_insert(&hashtable, strdup("NAME_1"), strdup("NAME_1"));
	hashtable_insert(&hashtable, strdup("NAME_2"), strdup("NAME_2"));
	hashtable_insert(&hashtable, strdup("NAME_3"), strdup("NAME_3"));
	hashtable_insert(&hashtable, strdup("NAME_4"), strdup("NAME_4"));
	hashtable_insert(&hashtable, strdup("NAME_5"), strdup("NAME_5"));
	value = hashtable_item_get(hashtable, "NAME_10");
	if (value)
		return (error(&hashtable, FIND_TEST_2, NOEXIST_ERR));
	if (!test_destroy(&hashtable, FIND_TEST_2))
		return (false);
	return (true);
}

int	find_tests(void)
{
	if (!find_one())
		return (false);
	if (!find_no_existing())
		return (false);
	return (true);
}
