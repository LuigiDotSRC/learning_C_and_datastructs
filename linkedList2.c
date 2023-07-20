#include <stdio.h>
#include <stdlib.h>

struct node{
    int data; 
    struct node* link; 
};

struct node* addNode(int node_data, struct node* current){
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = node_data; 
    temp->link = NULL; 
    current->link = temp;
    
    return temp; 
}

void printAll(struct node* head){
    int index = 0;
    while(head != NULL){
        printf("Index: %d, Address: %p, Value: %d, Link: %p\n",index,head,head->data,head->link);
        head = head->link;
        index++;
    }
}

int main()
{
    int num_nodes;
    struct node* head = (struct node*)malloc(sizeof(struct node)); 
    head->link = NULL; 
    head->data = 0;
    
    struct node* temp = head; 
    
    printf("Number of elements: ");
    scanf("%d",&num_nodes); 
    
    for(int i=0; i<num_nodes; i++){
        int num; 
        scanf("\n%d",&num); 
        temp = addNode(num, temp);
    }
    printAll(head);
    return 0;
}
