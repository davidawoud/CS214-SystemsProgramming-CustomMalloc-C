Malloc receives an integer as input and returns a pointer to the first index of free block of memory with a size matching the user's input. It prints an error statement and returns NULL if there is not a free block of memory large enough to match the user’s request. Malloc creates new metadata if there is enough space for the metadata plus an integer (4 bytes). Otherwise, malloc returns a pointer to the entire block, which is larger than what the user requested. In all cases, malloc edits the metadata to reflect that the memory block has been allocated.

Free receives a pointer as input and sets the metadata associated with that pointer to signal that the block is now free. When two free blocks are next to each other, the size held in the metadata of the first free block increases to encompass the second free block and its metadata. If the user provides a pointer to outside of memory, a pointer not returned by malloc, or a pointer to a free block, the program prints out a message detailing the type and location of the error before exiting.

The metadata is 5 bytes in total, 1 for a char indicating if the following memory block is allocated or not and 4 for an integer representing size.

For the library to be considered correct, Malloc returns a pointer to a block of memory with a size greater than or equal to the user's input, or NULL if no such block exists. 
When calling Free on a block of allocated memory, Malloc should be able to return a pointer to that now free block of memory if the size matches. Additionally, when calling Free on a block of allocated memory with a neighboring free block, the two combine to form one block, with a size equal to the sizes of both blocks plus the size of the metadata. If Free is called on an address out of range, an address not at the start of a block, or an address of a free block, it will return an error.

In crashtest1.c: Call free() on NULL pointer
In crashtest2.c: Call free() on an address out of bounds
In crashtest3.c: Call free() on an address not provided by malloc()
In crashtest4.c: Call free() on the address of a free block

In memgrind.c: 
Stress Test 1: malloc() and immediately free() a 1-byte chunk, 120 times
Stress Test 2: Use malloc() to get 120 1-byte chunks, storing the pointers in an array, then use free() to deallocate the chunks
Stress Test 3: Randomly choose between allocating a 1-byte chunk and storing the pointer in an array and deallocating one of the chunks in the array (if any)
Stress Test 4: Call malloc(1) until memory runs out, then frees the accumulated pointers
Stress Test 5: Call malloc(1) and free() at 3:1 ratio until memory is full, then free all pointers



