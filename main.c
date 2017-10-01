#include "includes/malloc.h"
#include "libft.h"


int main() {

	char *test1;
	
	test1 = malloc(3);
	test1 = ft_strcpy(test1, "ta\0");

	printf("%s\n", test1);

	show_alloc_mem();

	return 0;
}

// int    main()
// {
//     int        i = 0;
//     char    *win;
//
//     while (i++ < 10000)
//     {
//         if (!(win = (char*)malloc(sizeof(char) * 21)))
//         {
//             printf("Error\n");
//             return (0);
//         }
//         strcpy(win, "hey !!! It's working");
//         printf("%d: %s\n", i, win);
//     }
// }
