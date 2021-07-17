#include "../includes/hashtable.h"
#include <stdio.h>

int	main(void)
{
	t_hashtable	*hashtable;

	hashtable = hashtable_new(5);
	printf("[+] Created hashtable.\n");
	hashtable_destroy(&hashtable);
	if (hashtable != 0)
	{
		printf("[!] Hashtable still exists!");
		return (EXIT_FAILURE);
	}
	printf("[+] Hashtable has been destroyed.\n");
	return (EXIT_SUCCESS);
}
