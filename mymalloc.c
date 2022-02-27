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
//typedef int size_t;

void *mymalloc(size_t size, char *file, int line)
{
/*
    // check if the array is empty
    if (memory[0] == NULL) {
        memory[0] = NOT_ALLOC;
        memory[1] = MEM_SIZE - META_LENGTH;
    }

    // find a free chunk
    int index = 0;
    while (TRUE) {

        if (index >= MEM_SIZE)
            return NULL;

        char curr_alloc_stat = memory[index];
        int curr_alloc_size = memory[index+1];

        if (curr_alloc_stat == NOT_ALLOC && curr_alloc_size >= size + META_LENGTH)
            break;

        else {
            index = index + META_LENGTH + curr_alloc_size;
        }
    }


    // allocate a chunk of memory
    // sets up the metadata for the next block
    size_t curr_size = memory[index + STAT_LENGTH];
    memory[index + META_LENGTH + size] = NOT_ALLOC;
    memory[index + META_LENGTH + size + STAT_LENGTH] = curr_size - size;

    // adjusts the metadata of the block of memory to be returned
    memory[index] = ALLOC;
    memory[index+1] = size;
    int *p = &memory[index + META_LENGTH];

    return p;
    */
}

void myfree(void *ptr, char *file, int line)
{
    if (ptr < &memory[0] || ptr >= &memory[MEM_SIZE])
        EXIT_FAILURE;

    int index = 0;
    int prev_index = -1;
    while (index < MEM_SIZE)
    {
        char curr_alloc_stat = memory[index];
        size_t curr_alloc_size = memory[index+1];
        void *curr_ptr = &memory[index + META_LENGTH];
        int next_index = index + META_LENGTH + curr_alloc_size;

        if (curr_ptr > ptr)
            EXIT_FAILURE;
        if (curr_ptr < ptr)
        {
            prev_index = index;
            index = next_index;
            continue;
        }
        if (curr_alloc_stat == NOT_ALLOC)
            EXIT_FAILURE;

        char prev_alloc_stat = '9';
        if (prev_index != -1)
            prev_alloc_stat = memory[prev_index];
        size_t prev_alloc_size = memory[prev_index+1];
        
        char next_alloc_stat = memory[next_index];
        size_t next_alloc_size = memory[next_index+1];

        if (prev_alloc_stat == NOT_ALLOC && next_alloc_stat == NOT_ALLOC)
            memory[prev_index+1] = prev_alloc_size + curr_alloc_size + next_alloc_size + (2 * META_LENGTH);
        else if (prev_alloc_stat == NOT_ALLOC)
            memory[prev_index+1] = prev_alloc_size + curr_alloc_size + META_LENGTH;
        else if (next_alloc_stat == NOT_ALLOC)
        {
            memory[index] = NOT_ALLOC;
            memory[index+1] = curr_alloc_size + next_alloc_size + META_LENGTH;
        }
        else
            memory[index] = NOT_ALLOC;
    }
    
}
