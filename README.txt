Malloc receives an integer as input and returns a pointer to the first index of free block of memory with a size matching the user's input. It prints an error statement and returns NULL if there is not a free block of memory large enough to match the user’s request. Malloc creates new metadata if there is enough space for the metadata plus an integer (4 bytes). Otherwise, malloc returns a pointer to the entire block, which is larger than what the user requested. In all cases, malloc edits the metadata to reflect that the memory block has been allocated.

Free receives a pointer as input and sets the metadata associated with that pointer to signal that the block is now free. When two free blocks are next to each other, the size held in the metadata of the first free block increases to encompass the second free block and its metadata. If the user provides a pointer to outside of memory, a pointer not returned by malloc, or a pointer to a free block, the program prints out a message detailing the type and location of the error before exiting.

The metadata is 5 bytes in total, 1 for a char indicating if the following memory block is allocated or not and 4 for an integer representing size.

For the library to be considered correct, Malloc returns a pointer to a block of memory with a size greater than or equal to the user's input, or NULL if no such block exists. 
When calling Free on a block of allocated memory, Malloc should be able to return a pointer to that now free block of memory if the size matches. Additionally, when calling Free on a block of allocated memory with a neighboring free block, the two combine to form one block, with a size equal to the sizes of both blocks plus the size of the metadata. If Free is called on an address out of range, an address not at the start of a block, or an address of a free block, it will return an error.

Test 1: Call Malloc with a size greater than memory
Test 2: Call Malloc on a full memory array
Test 3: Call Free on an address outside the range of the memory array
Test 4: Call Free on an address not at the start of a block
Test 5: Call Free on an address at the start of a free block
Test 6: Call Malloc, then Free on the returned pointer, and Malloc again -> Pointers should be the same
Test 7: Fill the memory array completely with multiple calls to Malloc, Free some blocks, and then call Malloc again
Test 8: Call Malloc 4 times with size 1000, Free the middle 2 pointers, and then call Malloc with a size 2000

Stress Tests 1, 2, and 3 given in project assignment writeup
Stress Test 4: 
Stress Test 5: 



