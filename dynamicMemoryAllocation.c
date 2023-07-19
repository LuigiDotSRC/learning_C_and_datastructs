#include <stdio.h>
#include <stdlib.h>

int main()
{
    // DYNAMIC MEMORY MAPPING -- Using the Heap: 
    // malloc, callloc, realloc, free 
    
    // malloc: reserve a block of 4 bytes (size of integer)
    // malloc returns a void pointer which is then typecasted to integer pointer 
    // p then stores the address of the reserved block 
    
    // deallocate anything on the heap that is no longer needed using free()
    
    // calloc: same as malloc but takes 2 arguments arg1: num of elements, arg2: size of datatype
    // malloc doesnt initialize a value but calloc initializes the reserved spaces with 0 
    
    // realloc: if a block is reserved, realloc will change the size of the memory block 
    // arg1: pointer to starting address of existing block, arg2: size of new block 
    
    // USECASE 1: dynamic array size 
    int n; 
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    int* A = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){
        *(A+i) = 2*i;
        printf("Index: %d, Memory location: %p, Value: %d\n",i,A+i,*(A+i));
    }
    
    free(A);
    
    return 0;
    
}
