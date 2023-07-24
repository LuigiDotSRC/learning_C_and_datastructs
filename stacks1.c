#include <stdio.h>
#include <stdlib.h> 

#define STACK_SIZE 30
int stack[STACK_SIZE]; 
int top_index = -1; 

void push(int data){
    top_index++; 
    stack[top_index] = data; 
}

int pull(){
    int result = stack[top_index]; 
    stack[top_index] = 0; 
    top_index--; 
    
    return result; 
}

int peek(){
    return stack[top_index]; 
}

void printAll(){
    for(int i=0; i<=top_index; i++){
        printf("STACK POS: %d, DATA: %d\n",i,stack[i]);
    }
}

int main() 
{
    push(4);
    push(42);
    push(90);
    push(1204);
    push(1738);
    printAll(); 
    printf("\n------------------\nAfter:\n");
    pull();
    int number = pull();
    printAll();
    printf("The most recently pulled element is: %d\n", number);
    printf("The number at the top of the stack is: %d", peek());
}
