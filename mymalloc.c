#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

#define MEM_SIZE 4096
#define STAT_LENGTH 1
#define SIZE_LENGTH 8
#define META_LENGTH 9
#define NOT_ALLOC '0'
#define ALLOC '1'
#define SMALLEST_FREE 4
#define TRUE 1
#define FALSE 0

static char memory[MEM_SIZE];

void *mymalloc(size_t size, char *file, int line)
{
    // check if the array is empty
    if (memory[0] == NULL) {
        memory[0] = NOT_ALLOC;
        size_t* initialSizePointer = (size_t*)(&memory[1]);
        *initialSizePointer = MEM_SIZE - META_LENGTH;
    }
    // find a free chunk
    int index = 0;
    int createNewBlock = FALSE;
    while (TRUE) {
        if (index >= MEM_SIZE - META_LENGTH) {
        	printf("No memory available for malloc call in %s: line %d\n", file, line);
            return NULL;
        }
        char curr_alloc_stat = memory[index];
        size_t* curr_alloc_size_p = (size_t*)(&memory[index + STAT_LENGTH]);
        size_t curr_alloc_size = *curr_alloc_size_p;
        if (curr_alloc_stat == NOT_ALLOC && curr_alloc_size >= size) {
        	if (curr_alloc_size >= size + META_LENGTH + SMALLEST_FREE) {
        		createNewBlock = TRUE;
        	}
            // adjusts the metadata of the block of memory to be returned
            memory[index] = ALLOC;
    	    *curr_alloc_size_p = size;
            break;
        }
        else {
            index = index + META_LENGTH + curr_alloc_size;
        }
    }
    // allocate a chunk of memory
    // sets up the metadata for the next block
    if (createNewBlock) {
        size_t* curr_size_p = (size_t*)(&memory[index + STAT_LENGTH]);
    	size_t curr_size = *curr_size_p;
    	memory[index + META_LENGTH + size] = NOT_ALLOC;
        size_t* next_size_p = (size_t*)(&memory[index + META_LENGTH + size + STAT_LENGTH]);
    	*next_size_p = curr_size - size - META_LENGTH;
    }
    void *p = &memory[index + META_LENGTH];
    return p;
}

void myfree(void *ptr, char *file, int line)
{
    if (ptr == NULL)
    {
        printf("Null pointer at %s: line %d\n", file, line);
        exit(EXIT_FAILURE);
    }

    if (ptr < &memory[0] || ptr > &memory[MEM_SIZE - 1])
    {
        printf("pointer out of bounds (not provided by mymalloc) at %s: line %d\n", file, line);
        exit(EXIT_FAILURE);
    }

    int index = 0;
    int prev_index = -1;
    while (index < MEM_SIZE)
    {
        char curr_alloc_stat = memory[index];
        size_t *curr_alloc_size_p = (size_t *)(&memory[index + STAT_LENGTH]);
        size_t curr_alloc_size = *curr_alloc_size_p;
        void *curr_ptr = &memory[index + META_LENGTH];
        int next_index = index + META_LENGTH + curr_alloc_size;
        if (next_index >= MEM_SIZE)
            next_index = -1;

        if (curr_ptr > ptr)
        {
            printf("pointer in the middle of a memory block (not provided by mymalloc) at %s: line %d\n", file, line);
            exit(EXIT_FAILURE);
        }
        if (curr_ptr < ptr)
        {
            prev_index = index;
            index = next_index;
            continue;
        }
        if (curr_alloc_stat == NOT_ALLOC)
        {
            printf("trying to free a free memory block at %s: line %d\n", file, line);
            exit(EXIT_FAILURE);
        }

        // freeing a block
        char prev_alloc_stat = '9';
        size_t prev_alloc_size = 0;
        size_t *prev_alloc_size_p;
        if (prev_index != -1)
        {
            prev_alloc_stat = memory[prev_index];
            prev_alloc_size_p =  (size_t *) (&memory[prev_index + STAT_LENGTH]);
            prev_alloc_size = *prev_alloc_size_p;
        }
        
        char next_alloc_stat = '9';
        size_t next_alloc_size = 0;
        size_t *next_alloc_size_p;
        if (next_index != -1)
        {
            next_alloc_stat = memory[next_index];
            next_alloc_size_p =  (size_t *) (&memory[next_index + STAT_LENGTH]);
            next_alloc_size = *next_alloc_size_p;
        }

        if (prev_alloc_stat == NOT_ALLOC && next_alloc_stat == NOT_ALLOC)
            *prev_alloc_size_p = prev_alloc_size + curr_alloc_size + next_alloc_size + (2 * META_LENGTH);
        else if (prev_alloc_stat == NOT_ALLOC)
            *prev_alloc_size_p = prev_alloc_size + curr_alloc_size + META_LENGTH;
        else if (next_alloc_stat == NOT_ALLOC)
        {
            memory[index] = NOT_ALLOC;
            *curr_alloc_size_p = curr_alloc_size + next_alloc_size + META_LENGTH;
        }
        else
            memory[index] = NOT_ALLOC;

        break;
    }
    
}
