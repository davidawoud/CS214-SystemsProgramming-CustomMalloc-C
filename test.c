#include <stdio.h>
#include <stdlib.h>

static char mem[12];

int main(int argc, char const *argv[])
{
    printf("%c\n",mem[0]);
    /*
    char test_arr[12];
    test_arr[0] = 3;
    test_arr[4] = 4;
    test_arr[8] = 5;
    //int *p = (int*) &test_arr[0];
    //int *q = (int*) &test_arr[4];
    //int *r = (int*) &test_arr[8];
    printf("%d\n%d\n%d\n", test_arr[0], test_arr[4], test_arr[8]);
    //printf("%d\n", (int) test_arr[4]);
    */
    return 0;
}
