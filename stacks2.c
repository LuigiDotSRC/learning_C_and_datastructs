#include <stdio.h>
#include <stdlib.h>

// implementation of STACK using Linked List 

struct node{
    int data;
    struct node* link; 
};
struct node* top = NULL; 

void push(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = data; 
    new_node->link = top; 
    top = new_node;  
}

void pop(){
    struct node* target_node; 
    if(top == NULL){
        return; 
    }
    
    target_node = top; 
    top = top->link; 
    free(target_node);
    
}

void printAll(){
    struct node* stack_pointer = top; 
    int count = 0;
    while(stack_pointer != NULL){
        printf("ADDRESS: %p, DATA: %d, INDEX: %d\n",stack_pointer,stack_pointer->data,count);
        count++;
        stack_pointer = stack_pointer->link; 
    }
}

int main()
{
    push(3);
    push(90);
    push(100);
    push(21);
    push(6666);
    pop();
    printAll(); 
    return 0;
}
