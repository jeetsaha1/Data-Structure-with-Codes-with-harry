#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node * delete_first(struct Node * head){
    struct Node * ptr = head;
    head= head->next;
    free(ptr);
    return head;
}
int linked_list_traversal(struct Node* ptr){
    while (ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    //Allocate the memory for nodes in heap by linked list
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    //Link first and second nodes
    head->data = 7;
    head->next = second;
    
    //Link secon and third nodes
    second->data = 11;
    second->next = third;
    
    //Link third and fourth list
    third->data = 66;
    third->next = fourth;

    //Treminate the linked list
    fourth->data = 23;
    fourth->next = NULL;
    
    printf("Linked list before deletion:\n");
    linked_list_traversal(head);
    head=delete_first(head);
    printf("Linked list after deletion:\n");
    linked_list_traversal(head);

    return 0;
}