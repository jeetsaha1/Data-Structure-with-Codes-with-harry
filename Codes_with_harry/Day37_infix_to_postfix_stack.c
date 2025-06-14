#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    char *arr;
    int top;
};

int isFull(struct stack * ptr){
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
    
}

int isEmpty(struct stack * ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
    
}

void push(struct stack * ptr,int val){
    if(isFull(ptr))
        printf("Stack Overflow");
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}


char pop(struct stack * ptr){
    if(isEmpty(ptr))
        printf("Stack Underflow");
    else{
        char item = ptr->arr[ptr->top];
        ptr->top--;
        return item;
    }
}

void display(struct stack * ptr){
    for (int i = ptr->top; i >= 0; i--)
    {
        printf("Element : %d\n",(ptr->arr)[i]);
    }
    
}


int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack * ptr){
    return ptr->arr[0];
}

int isOperator(char  a){
    if(a == '+' ||a == '-' || a == '*' || a == '/' )
        return 1;
    else
        return 0;
}

int precedence(char  a){
    if(a == '*' || a == '/' )
        return 3;
    else if(a == '+' || a == '-' )
        return 2;
    else
        return 0;
}

char *infix_to_postfix(char *infix){
    struct stack * sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char *postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));

    int i = 0; //infix scanner
    int j = 0; //postfix filler

    while (infix[i] != '\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(isEmpty(sp)||precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
    
    

}

int main(){
    char * infix = "a+b-c/d-d*e";
     printf("%s",infix_to_postfix(infix));
    return 0;
}