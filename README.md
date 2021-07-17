# c_hashtable

[![.github/workflows/norminette.yml](https://github.com/c3b5aw/c_hashtable/actions/workflows/norminette.yml/badge.svg)](https://github.com/c3b5aw/c_hashtable/actions/workflows/norminette.yml) <br />
[![.github/workflows/tests.yml](https://github.com/c3b5aw/c_hashtable/actions/workflows/tests.yml/badge.svg)](https://github.com/c3b5aw/c_hashtable/actions/workflows/tests.yml) <br />

## usage

```text
Aim to emulate dictonnary table
```

### required header
```C
#include "includes/hashtable.c"
```

### data types
```C
typedef struct s_hashtable_item
{
	char		*key;
	void		*value;
}				t_hashtable_item;

typedef struct s_hashtable
{
	t_hashtable_item	**items;
	unsigned int		size;
	unsigned int		count;
}						t_hashtable;
```

### methods
```C
t_hashtable_item	*hashtable_item_create(char *key, void *value);
void				hashtable_item_destroy(t_hashtable_item *item);
t_hashtable_item	*hashtable_insert(t_hashtable **h, char *key, void *value);
t_hashtable			*hashtable_new(unsigned int size);
void				hashtable_destroy(t_hashtable **table);
```