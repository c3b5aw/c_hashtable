/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:49:52 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 09:20:31 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

bool	malloc_too_much(void)
{
	static char	buf[50] = {0};
	void		*ptr;
	t_hashtable	*hashtable;
	int			i;

	if (!test_init(&hashtable, 10, ADV_TEST_1))
		return (false);
	i = -1;
	while (++i < 50)
	{
		ptr = malloc(100);
		memset(ptr, 0, 100);
		sprintf(buf, "NAME_%d", i);
		hashtable_insert(&hashtable, strdup(buf), ptr);
	}
	if (!test_destroy(&hashtable, ADV_TEST_1))
		return (false);
	return (true);
}

bool	malloc_too_very_much(void)
{
	static char	buf[50] = {0};
	void		*ptr;
	t_hashtable	*hashtable;
	int			i;

	if (!test_init(&hashtable, 10, ADV_TEST_2))
		return (false);
	i = -1;
	while (++i < 500)
	{
		ptr = malloc(10);
		memset(ptr, 0, 10);
		sprintf(buf, "NAME_%d", i);
		hashtable_insert(&hashtable, strdup(buf), ptr);
	}
	if (!test_destroy(&hashtable, ADV_TEST_2))
		return (false);
	return (true);
}

bool	malloc_huge(void)
{
	static char	buf[50] = {0};
	void		*ptr;
	t_hashtable	*hashtable;
	int			i;

	if (!test_init(&hashtable, 1000, ADV_TEST_3))
		return (false);
	i = -1;
	while (++i < 2000)
	{
		ptr = malloc(10);
		memset(ptr, 0, 10);
		sprintf(buf, "NAME_%d", i);
		hashtable_insert(&hashtable, strdup(buf), ptr);
	}
	if (!test_destroy(&hashtable, ADV_TEST_3))
		return (false);
	return (true);
}

bool	adv_tests(void)
{
	if (!malloc_too_much())
		return (false);
	if (!malloc_too_very_much())
		return (false);
	if (!malloc_huge())
		return (false);
	return (true);
}
