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

//insert at a speciied index
struct Node * insert_after_node(struct Node *head, struct Node *prevnode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->next= prevnode->next;
    prevnode->next = ptr;
    ptr->data = data;
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
    head = insert_after_node(head, second,1);
    linked_list_traversal(head);

    return 0;
}