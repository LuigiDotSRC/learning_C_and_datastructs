#include <stdio.h>
#include <stdlib.h> 

// LINKED LIST implementation of queues 

struct node{
    int data; 
    struct node* link;
};
struct node* front = NULL; 
struct node* rear = NULL; 

void enQueue(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL; 
    
    if(front == NULL && rear == NULL){
        front = rear = temp; 
        return; 
    }
    rear->link = temp; 
    rear = temp; 
}

void deQueue(){
    struct node* temp = front; 
    if(front == NULL){
        return; 
    }
    if(front == rear){
        front = rear = NULL; 
    }else{
        front = front->link; 
    }
    free(temp);
    
}

void printAll(){
    struct node* ll_pointer = front;
    int counter = 0;
    while(ll_pointer != NULL){
        printf("ADDRESS: %p, DATA: %d, POSITION: %d\n",ll_pointer,ll_pointer->data,counter);
        counter++;
        ll_pointer = ll_pointer->link;
    }
}



int main()
{
    enQueue(3);
    enQueue(8);
    enQueue(9);
    deQueue();
    printAll(); 
    return 0;
}
