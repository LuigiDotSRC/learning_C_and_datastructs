#include <stdio.h>
#include <stdlib.h> 

// in-depth coverage of all Linked-List functions to reinforce knowledge 

struct node{
  int data; 
  struct node* link;  
};

struct node* createLinkedList(int* num_array, int array_size){
    // create a linkedlist given the address of the array of initial elements & number of elements 
    // returns the address of the head of the new linkedlist 
    
    struct node* head = (struct node*)malloc(sizeof(struct node)); 
    head->data = *(num_array); 
    head->link = NULL; 
    
    struct node* previous_node = head; 
    for(int i=1; i<array_size; i++){
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = *(num_array + i); 
        new_node->link = NULL;
        
        previous_node->link = new_node; 
        previous_node = new_node;
    }
    
    return head; 
}

void printAllNodes(struct node* head){
    // given the address of the head node, traverse all nodes sequentially and print their data 
    
    int index = 0; 
    while(head != NULL){
        printf("ADDRESS: %p, DATA: %d, INDEX: %d\n",head,head->data,index);
        index++; 
        head = head->link; 
    }
}

void addElement(struct node* head, int data, int index){
    // given the index position, place the data in the given node position
    // SC1: if there is an existing node, displace it to the right by 1 index (cutoff previous node link and new node will link to displaced node)
    // SC2: if the index is 0, do nothing since the head should not be changed 
    
    int counter = 0; 
    struct node* previous_node = head; 
    while(head != NULL){
        if(counter == index){
            struct node* old_node = head; 
            struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
            
            new_node->data = data; 
            new_node->link = old_node; 
            previous_node->link = new_node; 
        }
        counter++; 
        previous_node = head; 
        head = head->link; 
    }
    
}

int main()
{
    int numbers[] = {0,6,3,541,78,69}; 
    int numbers_size = sizeof(numbers) / sizeof(numbers[0]); 
    
    struct node* head = createLinkedList(numbers, numbers_size); 
    printAllNodes(head); 
    
    addElement(head, 420, 2); 
    printf("\n---------------------\n");
    printAllNodes(head);
    
    return 0;
}
