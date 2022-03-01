#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

int main(int argc, char **argv)
{
    char *p = malloc(sizeof(char));
    free(p+1);
    return 0;
}
