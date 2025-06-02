#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;    
};



int isFull(struct queue * q){
    if(q->r == q->size-1){
        return 1;
    } 
    return 0;
}

int isEmpty(struct queue * q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q,int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
        
    }
    return a;
}

// void display(struct queue *q){
//     for (int i = 0; i < q->size; i++)
//     {
//         printf("Element : %d\n",q->arr[i]);
//     }
    
// }

int main(){
     struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 4;
    q->f = q->r = 0;
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
    

     // Free memory
    free(q->arr);
    free(q);
    return 0;
}