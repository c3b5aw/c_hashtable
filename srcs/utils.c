/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:27:15 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 01:13:17 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	__strlen(const char *s)
{
	const char	*anchor;

	anchor = s;
	while (*++s)
		;
	return (s - anchor);
}

int	__strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	*__memcpy(void *dst, const void *src, unsigned long n)
{
	char		*ptr_dest;

	ptr_dest = dst;
	if (n == 0 || dst == src || !src)
		return (dst);
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return ((void *)(ptr_dest));
}

char	*__strdup(char *s)
{
	char			*ret;
	unsigned long	_size;

	if (!s)
		return (0);
	_size = __strlen(s) + 1;
	ret = (char *)malloc(sizeof(char) * _size);
	if (!ret)
		return (0);
	ret = __memcpy(ret, s, _size);
	return (ret);
}
