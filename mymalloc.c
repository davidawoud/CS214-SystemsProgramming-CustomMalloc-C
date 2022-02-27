#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

#define MEM_SIZE 4096
#define STAT_LENGTH 1
#define SIZE_LENGTH 4
#define META_LENGTH 5
#define NOT_ALLOC '0'
#define ALLOC '1'
#define SMAlLEST_FREE 4
#define TRUE 1
#define FALSE 0

static char memory[MEM_SIZE];
typedef int size_t;

void *mymalloc(size_t size, char *file, int line) {
    // check if the array is empty
    if (memory[0] == NULL) {
        memory[0] = NOT_ALLOC;
        memory[1] = MEM_SIZE - META_LENGTH;
    }

    // find a free chunk
    int index = 0;
    int createNewBlock = FALSE;
    while (TRUE) {

        if (index >= MEM_SIZE)
            return NULL;

        char curr_alloc_stat = memory[index];
        size_t curr_alloc_size = memory[index+1];

        if (curr_alloc_stat == NOT_ALLOC && curr_alloc_size >= size) {
        	if (curr_alloc_size >= size + META_LENGTH + SMALLEST_FREE) {
        		createNewBlock = TRUE;
        	}
            break;
        }
        else {
            index = index + META_LENGTH + curr_alloc_size;
        }
    }


    // allocate a chunk of memory
    // sets up the metadata for the next block
    if (createNewBlock) {
    	size_t curr_size = memory[index + STAT_SIZE];
    	memory[index + META_LENGTH + size] = NOT_ALLOC;
    	memory[index + META_LENGTH + size + STAT_LENGTH] = curr_size - size - META_LENGTH;

    	// adjusts the metadata of the block of memory to be returned
    	memory[index] = ALLOC;
    	memory[index+1] = size;
    }
    else
    	memory[index] = ALLOC;

    int *p = &memory[index + META_LENGTH];
    return p;




    return p;
}

void myfree(void *ptr, char *file, int line)
{
	...
}
