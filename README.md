# c_hashtable

[![.github/workflows/norminette.yml](https://github.com/c3b5aw/c_hashtable/actions/workflows/norminette.yml/badge.svg)](https://github.com/c3b5aw/c_hashtable/actions/workflows/norminette.yml) <br />
[![.github/workflows/tests.yml](https://github.com/c3b5aw/c_hashtable/actions/workflows/tests.yml/badge.svg)](https://github.com/c3b5aw/c_hashtable/actions/workflows/tests.yml) <br />
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/4dd2af2c25784a18a92d5ac8f55f426e)](https://www.codacy.com/gh/c3b5aw/c_hashtable/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=c3b5aw/c_hashtable&amp;utm_campaign=Badge_Grade)

## usage

```C
#include "includes/hashtable.c"

int	main(void)
{
	t_hashtable	*hashtable;

	hashtable = hashtable_new(5);
	if (!hashtable)
		return (EXIT_FAILURE);
	hashtable_destroy(&hashtable, true);
	if (hashtable)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
```

### required header
```C
#include "includes/hashtable.c"
```

### data types
```C
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
```

### item methods
```C
t_hashtable_item	*hashtable_item_create(char *key, void *value);
void			hashtable_item_destroy(t_hashtable_item *item, bool dealloc_value);
t_hashtable_item	*hashtable_item_copy(t_hashtable **dst, t_hashtable_item *item);
void			*hashtable_item_get(t_hashtable *hashtable, char *key);
void				hashtable_item_remove( \
	t_hashtable *hashtable, t_hashtable_item *item);
t_hashtable_item	*hashtable_item_copy( \
	t_hashtable **dst, t_hashtable_item *item);
```

### table method

```C
t_hashtable_item	*hashtable_insert(t_hashtable **h, char *key, void *value);
t_hashtable		*hashtable_new(unsigned int size);
void			hashtable_destroy(t_hashtable **table, bool dealloc_value);
bool			hashtable_copy(t_hashtable **src, t_hashtable **dst);
void			hashtable_iter(t_hashtable *h, void (*f)(t_hashtable_item *));
```