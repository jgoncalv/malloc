#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *test;
  char *test2;

  test = malloc(10);
  test2 = malloc(10);
  strcpy(test, "111111111111\0");
  strcpy(test2, "22222222222\0");
  printf("%s %s\n", test, test2);
  free(test2);
  printf("%s\n", test2);
  return 0;
}
