//DEQueue

#include<stdio.h>
#include<stdlib.h>

struct DEQueue {
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct DEQueue * ptr){
    if (ptr->f == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct DEQueue * ptr){
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    return 0;
}

void enqueue_rear(struct DEQueue * ptr,int val){
    if (isFull(ptr))
    {
        printf("Queue overflow");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]= val;
    }
    
}

void enqueue_front(struct DEQueue * q,int val){
    if(isFull(q))
        printf("Queue overflow");
    else{
        q->f--;
        q->arr[q->f]= val;
    }
}

int dequeue_front(struct DEQueue * q){
    int item = -1;
    if(isEmpty(q))
        printf("Queue underflow");
    else{
        item = q->arr[q->f];
        q->f++;
        return item;
    }
}

int dequeue_rear(struct DEQueue *q){
    int item = -1;
    if(isEmpty(q))
        printf("Queue underflow");
    else{
        item = q->arr[q->r];
        q->r--;
        return item;
    }
}

void display(struct DEQueue *q){
    printf("Queue elements: ");
    for(int i = q->f+1; i <= q->r; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main(){
    struct DEQueue *deq = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    deq->size = 10;
    deq->f = deq->r = -1;
    deq->arr = (int*)malloc(deq->size * sizeof(int));


    enqueue_rear(deq,12);
    enqueue_rear(deq,23);
    enqueue_rear(deq,45);
    enqueue_rear(deq,67);
    enqueue_rear(deq,43);
    enqueue_rear(deq,11);
    enqueue_rear(deq,15);
    enqueue_rear(deq,10);
    enqueue_front(deq,47);
    printf("The poped item is : %d\n",dequeue_front(deq));
    printf("The poped item is : %d\n",dequeue_rear(deq));
    display(deq);
    return 0;
}