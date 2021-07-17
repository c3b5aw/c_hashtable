/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:43:04 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/17 23:58:17 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <string.h>
# include "../includes/hashtable.h"

bool	test_init(t_hashtable **hashtable, unsigned int size, char *test_name);
bool	test_destroy(t_hashtable **hashtable, char *test_name);
int		basic_tests(void);

#endif
