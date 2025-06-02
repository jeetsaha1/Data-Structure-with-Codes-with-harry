#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;}
}


int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else
        return 0;
}


void push(struct stack * ptr){
    if(isFull(ptr)){
        printf("Stack Overflow.");
    }
    else{
        int val;
        printf("Enter the element to push : ");
        scanf("%d",&val);
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}


int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow.");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("Poped item: %d",val);
        return val;
    }
}

void display(struct stack * ptr){
    for (int i = ptr->top; i >=0; i--)
    {
        printf("%d ",ptr->arr[i]);
    }
    
}


int main(){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 8;
    sp->top=-1;
    sp->arr = (int*)malloc(sp->size*sizeof(int));
    int choice;
    
    do{
        printf("\n\nEnter the choice: \nPush->1\nPop->2\nDisplay->3\nExit->4\n__________________________\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(sp);
            break;
        
        case 2:
            printf("Poped item:%d ",pop(sp));
            break;
            
        case 3:
            display(sp);
            break;
            
        case 4:
            break;
            
        default:
            printf("You give wrong input.");
            break;
        }
    }while(choice!=4);

    return 0;
}