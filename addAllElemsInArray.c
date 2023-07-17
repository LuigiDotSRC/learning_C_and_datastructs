#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int num_elements; 
    int sum = 0; 
    
    scanf("%d",&num_elements);
    int array_num[num_elements]; 

    for(int i=0; i<num_elements; i++){
        scanf("%d",&array_num[i]);
    }
    
    for(int i=0; i<num_elements; i++){
        sum += array_num[i];
    }
    
    printf("%d",sum);
    return 0;
}
