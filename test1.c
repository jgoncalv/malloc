#include "includes/malloc.h"
//#include <stdlib.h>

int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 10)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		//printf("==== BREAK  ==== : %p et %p\n", addr, addr - sizeof(t_alloc));
		free(addr);
		i++;
	}
	show_alloc_mem();
	return 0;
}
