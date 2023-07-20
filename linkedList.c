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

void insert_node(struct node* current_node, int node_data){
    // insert node directly to the right of the current node: 
    // current node link must be updated to match new node 
    // the address of the next node must be stored inside the new node 
    
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->link = current_node->link; 
    current_node->link = new_node; 
    
    new_node->data = node_data; 
}

struct node* traverse_nodes(struct node* head, int index){
    struct node* traveller = head; 
    for(int i=0; i<index; i++){
        if(traveller->link != NULL){
            traveller = traveller->link;
        }
    }
    return traveller;
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
    
    struct node* target = head->link; 
    insert_node(target, 18790);
    printf("\n--------------\n");
    printf("The number of nodes is: %d",count_of_nodes(head));
    
    struct node* target2 = traverse_nodes(head, 6); 
    printf("\n--------------\n");
    printf("%d",target2->data);
    
    return 0; 
}
