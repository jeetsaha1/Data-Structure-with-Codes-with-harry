#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node)); //Create a node pointer and allocate the memory in the heap
    n->data = data; // setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL

    return n;
}

int main(){
    //Constructing the real node - using function 
    struct Node * p = createNode(2);
    struct Node * p1 = createNode(23);
    struct Node * p2 = createNode(21);

    
    //Linking the root with the left and the right children
    p->left = p1;
    p->right = p2;
    return 0;
}

