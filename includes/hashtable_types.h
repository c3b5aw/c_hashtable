/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:47:46 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 09:28:46 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_TYPES_H
# define HASHTABLE_TYPES_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_hashtable_item
{
	char		*key;
	void		*value;
}				t_hashtable_item;

typedef struct s_hashtable_bucket
{
	t_hashtable_item			*item;
	struct s_hashtable_bucket	*next;
}								t_hashtable_bucket;

typedef struct s_hashtable
{
	t_hashtable_item	**items;
	t_hashtable_bucket	**buckets;
	unsigned int		size;
	unsigned int		count;
}						t_hashtable;

#endif