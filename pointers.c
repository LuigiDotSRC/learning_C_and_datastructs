#include <stdio.h>

int main()
{
    int num_array[5]; 
    num_array[1] = 4;
    num_array[4] = 7;
    num_array[3] = 12;
    int* num_pointer = &num_array; 
    
    for(int i=0; i<5; i++){
        printf("The value at location %p is: %d\n",(num_pointer+i),*(num_pointer+i));
    }
    
    printf("%p %d",num_array+1,*(num_array+1));
    
    return 0;
}
