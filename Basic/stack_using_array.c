#include<stdio.h>
#define N 5
int stack[5];
int top = -1;

void push(){
    int x;
    printf("Enter the number: ");
    scanf("%d",&x);
    if (top == N-1)
        printf("Overflow Condition.");
    else{
        top++;
        stack[top]=x;
    }   
}

void pop(){
    int item;
    if (top==-1)
    {
        printf("Underflow Condition.");
    }
    else{
        item = stack[top];
        top--;
        printf("Poped item : %d",item);
    }
}

void peek(){
    if (top==-1)
    {
        printf("The stack is empty.");
    }
    else{
        printf("%d",stack[top]);
    }
    
}

void display(){
    printf("\nThe elements are:");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n",stack[i]);
    }
    
}
int main(){
    int ch;
    do{
        
        printf("\n_____________________\nEnter the choice: \n1.Push \n2.Pop \n3.Peek \n4.Display \n0.Exit\n_____________________\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 0:
                break;

            case 1:
                push();
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                peek();
                break;
            
            case 4:
                display();
                break;
            
            default:
            printf("You give wrong input.");
                break;
        }
}while (ch!=0);

    return 0;
}