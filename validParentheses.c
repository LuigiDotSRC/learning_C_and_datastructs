// LEETCODE: https://leetcode.com/problems/valid-parentheses/ 
struct node{
    char data;
    struct node* link; 
};

struct node* top = NULL; // stack implementation using linked list 

void push(char data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = data; 
    new_node->link = top; 
    top = new_node; 
}

char peek(){
    return top->data; 
}

void pop(){
    if(top == NULL){
        return; 
    } 
    struct node* temp_pointer = top; 
    top = top->link; 
    free(temp_pointer);
}

bool isValid(char * s){
    top = NULL; 
    int count = 0; 
    while(*(s+count) != '\0'){
        char current = *(s+count);

        if(current == '(' || current == '{' || current == '['){
            push(current); 
        }else{
            if(top == NULL){
                return false;
            }
            char recent_open = peek(); 
            if((recent_open == '(' && current == ')') || (recent_open == '{' && current == '}') || (recent_open == '[' && current == ']')){  
                pop();
            }else{
                return false;
            }
        }
        count++;
    }
    if(top != NULL){
        printf("%c",top->data);
        return false;
    }
    return true;
}
