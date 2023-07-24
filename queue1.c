#include <stdio.h>
#include <stdlib.h> 

#define MAX_CAPACITY 20

int queue[MAX_CAPACITY]; 
int front = -1;
int rear = -1; 

bool isEmpty(){
    if(front == -1 && rear == -1){
        return true; 
    }
    return false; 
}

void enQueue(int data){
    if(isEmpty()){
        front = 0; 
    }
    // also check if the queue is full 
    rear++; 
    queue[rear] = data; 
}

int deQueue(){
    int result = queue[front];
    front++; // check if valid operation 
    return result; 
}

void printAll(){
    for(int i=front; i<rear+1; i++){
        printf("ADDRESS: %p, DATA: %d, INDEX: %d, FRONT: %d, REAR: %d",queue+i,*(queue+i),i,front,rear);
    }
}

int main()
{
    printf("Hello World");

    return 0;
}
