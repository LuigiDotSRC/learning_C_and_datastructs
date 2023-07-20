#include <stdio.h>
#include <stdlib.h> 

struct node{
  int data; 
  struct node* link; 
};

int count_of_nodes(struct node* head){
    int count = 0;
    
    if(head == NULL){
        return 0; 
    }
    
    struct node* traveller = head;
    while(traveller != NULL){
        count++;
        printf("Count: %d, Current address: %p, Data: %d\n",count,traveller,traveller->data);
        traveller = traveller->link; 
    }
    
    return count; 
}

int main()
{
    struct node* head = NULL; 
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45; 
    head->link = NULL;
    
    struct node* current = (struct node *)malloc(sizeof(struct node));
    current->data = 90; 
    current->link = NULL;
    head->link = current;
    
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 135; 
    current->link = NULL;
    head->link->link = current;
    
    printf("The number of nodes is: %d",count_of_nodes(head));
    
    return 0; 
}
