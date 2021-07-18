/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 23:37:39 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 04:50:55 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	if (!basic_tests())
		return (EXIT_FAILURE);
	if (!find_tests())
		return (EXIT_FAILURE);
	if (!adv_tests())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
