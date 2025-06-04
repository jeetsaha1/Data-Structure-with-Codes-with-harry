#include<stdio.h>
#include<stdlib.h>
//Create a linked list
struct Node
{
    int data;
    struct Node * next;
};

//Initialize the top
struct Node *top =  NULL;

//traversal the linked list
void linked_list_traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}
//Declearing the function isEmpty
int isEmpty(struct Node *top){
    if (top==NULL)
        return 1;
    else
        return 0;
}

//Declearing the function isFull
int isFull(struct Node *top){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n==NULL)
        return 1;
    else
        return 0;
}

//Declearing the function push
struct Node * push(struct Node * top,int x){
    
    if(isFull(top)){
        printf("Stack overload.");
    }
    else{
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

//Declearing the function pop
int pop(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack Underflow.");
    }
    else{
        struct Node *n = tp;
        int item = n->data;
        top=tp->next;
        free(n);
        return item;
    }
}

//Declearing the peek function
int peek(int pos){
    struct Node * ptr = top;
    for (int i =0; (i<pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL)
        return ptr->data;
    else
        return -1;
}

//Declearing the stack_top to print the top most element of stack
int stack_top(struct Node *ptr){
    return ptr->data;
}

//Declearing the stack_bottom to print the bottom most element of stack
int stack_bottom(struct Node *ptr){
    // struct Node * ptr = top;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    return ptr->data;
}

int main(){
    top = push(top,78);
    top = push(top,7);
    top = push(top,8);
    linked_list_traversal(top);
    printf("Poped element: %d\n",pop(top));
    linked_list_traversal(top);
    printf("The Picked element: %d",peek(2));
    printf("The Top element: %d",stack_top(top));
    printf("The bottom element: %d",stack_bottom(top));
    return 0;
}