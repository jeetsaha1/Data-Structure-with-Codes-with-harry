#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int linked_list_traversal(struct Node* ptr){
    while (ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

//insert at last
struct Node * insert_at_end(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    int i=0;
    struct Node * p = head;
    while (p->next!= NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;

    //Allocate the memory for nodes in heap by linked list
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //Link first and second nodes
    head->data = 7;
    head->next = second;
    
    //Link secon and third nodes
    second->data = 11;
    second->next = third;
    
    //terminate the linked list
    third->data = 66;
    third->next = NULL;

    linked_list_traversal(head);
    printf("\n");
    head = insert_at_end(head, 45);
    linked_list_traversal(head);

    return 0;
}