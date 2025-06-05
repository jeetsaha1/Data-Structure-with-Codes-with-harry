#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    char *arr;
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
    if (isFull(ptr))
    {
        printf("Stack overflow.");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack * ptr){
    if (isEmpty(ptr))
    {
        printf("Stack underflow");
    }
    else{
        char item = ptr->arr[ptr->top];
        ptr->top--;
        return item;
    }
    
}

int match(char val1, char val2){
    if(val1 == '(' && val2 ==')')
        return 1;
    else if(val1 == '[' && val2 ==']')
        return 1;
    else if(val1 == '{' && val2 =='}')
        return 1;
    else
        return 0;
}
int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}


int parenthesis_is_change(char * exp){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));;
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size*sizeof(char));

    char poped_item;
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i] == '('||exp[i] == '{'||exp[i] == '[')
        {
            push(s,exp[i]);
        }
        else if(exp[i] == ')'||exp[i] == ']'||exp[i] == '}'){
            if (isEmpty(s))
            {
                return 0;
            }
            poped_item = pop(s);
            if(!match(poped_item,exp[i]))
                return 0;
        }
        
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
        return 0;
    
    
}

int main(){
    char *exp = "1+2()";
    if (parenthesis_is_change(exp))
    {
        printf("The parenthesis is matched.");
    }
    else
        printf("The parenthesis is not matched.");
    
    return 0;
}