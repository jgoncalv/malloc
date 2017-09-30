#include "includes/malloc.h"
#include "libft.h"


int main() {

	char *test;

	test = malloc(3);

	test[0] = 't';
	test[1] = 'a';
	test[2] = '\0';

	ft_putstr(test);

	test = malloc(10);
	test = "vvoovvoov\0";
	ft_putstr(test);


		test = malloc(3000);
		test = "vvoov\0";
		ft_putstr(test);

	return 0;
}
