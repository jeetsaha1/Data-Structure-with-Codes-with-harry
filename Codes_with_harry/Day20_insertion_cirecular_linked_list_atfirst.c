#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};

void Circular_linked_list_tarversal(struct Node * head)
{
    struct Node * ptr = head;
    printf("Element: %d\n",ptr->data);
    ptr = ptr->next;
    while(ptr!=head){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr ->data = data;
    struct Node * p = head ->next;
    while (p->next!=head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head= ptr;
    return head;
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node * fourth;

    //Allocate the memory for nodes in heap by linked list
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    //Link first and second nodes
    head->data = 7;
    head->next = second;
    
    //Link second and third nodes
    second->data = 11;
    second->next = third;
    
    //link third and fourth list
    third->data = 66;
    third->next = fourth;

    //link fourth and first list
    fourth->data = 56;
    fourth->next = head;
    printf("Linked list before insertion:\n");
    Circular_linked_list_tarversal(head);
    printf("The list after insertion:\n");
    head = insertAtFirst(head,47);
    Circular_linked_list_tarversal(head);
    return 0;
}