#include "includes/malloc.h"
//#include <stdlib.h>

int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 10)
	{
		addr = (char*)malloc(1);
		addr[0] = 42;
		printf("%s %p %lu %lu\n", addr, addr, sizeof(t_alloc), sizeof(t_zone));
		addr = (char*)realloc(addr, 2);

		addr[1] = 43;
		//printf("==== BREAK  ==== : %p et %p\n", addr, addr - sizeof(t_alloc));
		printf("%s %p\n", addr, addr);
		//free(addr);
		i++;
	}
	show_alloc_mem();
	return 0;
}
