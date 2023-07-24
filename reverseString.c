#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reverse word using stack  

#define MAX_INPUT 100

char* reverse(char word[]){
    int top_stack = -1; 
    char stack[MAX_INPUT]; 
    
    for(int i=0; i<strlen(word); i++){
        top_stack++; 
        stack[top_stack] = word[i];
    }
    
    for(int i=0; i<strlen(word); i++){
        word[i] = stack[top_stack];
        top_stack--; 
    }
    
    return word; 
    
}

int main()
{
    char word[] = "Hello World!";
    printf("%s",reverse(word));
    return 0; 
}
