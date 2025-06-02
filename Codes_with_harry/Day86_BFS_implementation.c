#include<stdio.h>
#include<stdlib.h>

//implementation of queue

//Declear the structure of queue
struct queue{
    int size ;
    int f;
    int r;
    int *arr;
};

//Declaration of isFull function 
int isFull(struct queue *q){
    if (q->r == q->size -1)
    {
        return 1;
    }
    return 0;
}

//Declaration of isEmpty function 
int isEmpty(struct queue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

//declearation of enqueue for inserting the data
void enqueue(struct queue * q, int val){
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
    
}

//decleartaion of dequeue for deleting the data
int dequeue(struct queue * q){
    int val = -1;
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else{
        q->f++;
        val = q->arr[q->f] ;
    }
    return val;
}

int main(){
    //initialize the array
     struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 400;
    q->f = q->r = 0;
    q->arr = (int*)malloc(q->size*sizeof(int));

    
    //BFS implementation
    int node;
    int i =1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {0,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    printf("%d",i);
    visited[i] = 1;
    enqueue(q,i);       //For exploration
    while (!isEmpty(q))
    {
        int node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] ==1 && visited[j]==0)
            {
                printf("%d",j);
                visited[j] =  1;
                enqueue(q,j);
            }
            
        }
        
    }
    
    return 0;
}