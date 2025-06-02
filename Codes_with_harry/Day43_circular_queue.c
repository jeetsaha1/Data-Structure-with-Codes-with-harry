#include<stdio.h>
#include<stdlib.h>
struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if ((q->r+1)%q->size==q->f)
    {
        return 1;
    }
    else
        return 0;
    
}

int isEmpty(struct queue *q){
    if (q->r==q->f)
    {
        return 1;
    }
    else
        return 0;
    
}

void enqueue(struct queue *q,int val){
    if (isFull(q))
    {
        printf("Queue overflow");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
    
}

int dequeue(struct queue *q){
    int val = -1;
    if (isEmpty(q))
    {
        printf("Queue underflow");
    }
    else{
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
        return val;
    }
    
}



int main(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));
     enqueue(q,12);
    enqueue(q,24);
    enqueue(q,45);
    // enqueue(q,36);
    // enqueue(q,78);
    // enqueue(q,90);
    // enqueue(q,67);
    // enqueue(q,49);
    // enqueue(q,50);
    // enqueue(q,34);
    // display(q);
    printf("The deleted element : %d\n",dequeue(q));
    printf("The deleted element : %d\n",dequeue(q));
    printf("The deleted element : %d\n",dequeue(q));
    enqueue(q,12);
    enqueue(q,24);
    enqueue(q,45);

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue is full\n");
    }

    return 0;
}