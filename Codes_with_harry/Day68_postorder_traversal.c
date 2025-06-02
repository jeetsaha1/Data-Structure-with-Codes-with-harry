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

struct Node * postorder(struct Node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    //Constructing the real node - using function 
    struct Node * p = createNode(4);
    struct Node * p1 = createNode(1);
    struct Node * p2 = createNode(6);
    struct Node * p3 = createNode(5);
    struct Node * p4 = createNode(2);


    //Finally the tree looked like this:
    //       4
    //      / \
    //     1   6
    //    / \
    //   5   2


    //Linking the root with the left and the right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postorder(p);
    return 0;
}

