#include "mymalloc.c"

//Coalesce testing
int *pointer1 = malloc(1000);
int *pointer2 = malloc(1000);
int *pointer3 = malloc(1000);
int *pointer4 = malloc(1000);
free(pointer2);
free(pointer3);
int *pointer5 = malloc(2000);
