#include "includes/malloc.h"


int main() {

	char *test;

	test = malloc(3);

	test[0] = 't';
	test[1] = 'a';
	test[2] = '\0';

	return 0;
}
