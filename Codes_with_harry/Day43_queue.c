#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node * next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void enqueue(int val){
    struct Node * n =(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue overlow");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next =n;
            r=n;
        }
    }
}


int linked_list_traversal(struct Node* ptr){
    while (ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int dequeue (){
    int val = -1;
    struct Node * ptr = f;
    if (f==NULL)
    {
        printf("Queue underflow");
    }
    else{
        f=f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
    

}

int main(){
    enqueue(34);
    enqueue(23);
    enqueue(45);
    linked_list_traversal(f);
    dequeue();
    printf("\n");
    linked_list_traversal(f);
    return 0;
}