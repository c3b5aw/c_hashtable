/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:43:04 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 04:54:19 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <string.h>
# include "../includes/hashtable.h"

# define NOEXIST_ERR	"SHOULD NOT EXIST"
# define EXIST_ERR		"SHOULD EXIST"
# define FIND_TEST_1 	"FIND_ONE_TEST"
# define FIND_TEST_2 	"FIND_NO_EXISTING_TEST"
# define FIND_TEST_3 	"FIND_REMOVED_ONE"
# define ADV_TEST_1		"MALLOC_OVERFLOW"

bool	test_init(t_hashtable **hashtable, unsigned int size, char *test_name);
bool	test_destroy(t_hashtable **hashtable, char *test_name);
bool		basic_tests(void);
bool		find_tests(void);
bool		adv_tests(void);
int		error(t_hashtable **h, char *test_name, char *error);

#endif
