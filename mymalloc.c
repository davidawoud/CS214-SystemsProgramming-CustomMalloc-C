#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

#define MEM_SIZE 4096
#define STAT_LENGTH 1
#define SIZE_LENGTH 4
#define META_LENGTH 5
#define NOT_ALLOC '0'
#define ALLOC '1'
#define TRUE 1
#define FALSE 0

static char memory[MEM_SIZE];

void *mymalloc(size_t size, char *file, int line)
{
    // check if the array is empty
    if (memory[0] == NULL)
    {
        memory[0] = NOT_ALLOC;
        memory[1] = MEM_SIZE - META_LENGTH;
    }

    // find a free chunk
    int index = 0;
    while (1)
    {
        if (index >= MEM_SIZE)
            return NULL;

        char curr_alloc_stat = memory[index];
        int curr_alloc_size = memory[index+1];

        if(curr_alloc_stat == NOT_ALLOC && curr_alloc_size >= size)
            break;
        else
        {
            index = index + META_LENGTH + curr_alloc_size;
        }
    }


    // allocate a chunk of memory
    char alloc
    size_t alloc_size

    memory[0] = alloc
    memory[1] = alloc_size
    int *p = &memory[1]
}

void myfree(void *ptr, char *file, int line)
{
    ...
}