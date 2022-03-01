#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

int main(int argc, char **argv)
{
    char x = 'v';
    char *p = &x;
    free(p);
    return 0;
}
