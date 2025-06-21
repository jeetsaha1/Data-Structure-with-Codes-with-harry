// Count Total Nodes in a Binary Tree
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int val){
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int count(struct Node * root){
    int root_count = 1;
    int sum = 0;
    if(root == NULL){
        return 0;
    }
    else{
        int left_count = count(root->left);
        int right_count = count(root->right);
        sum = root_count+left_count+right_count;
    }

    return sum;
}

struct Node *  preorder(struct Node *root){
    if(root != NULL){
        printf("Element : %d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct Node * p = createNode(1);
    struct Node * p1 = createNode(2);
    struct Node * p2 = createNode(3);
    struct Node * p3 = createNode(4);
    struct Node * p4 = createNode(5);

    p->left = p1 ;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Displaying preorder traversal:\n");
    preorder(p);
    printf("The number of the node is %d",count(p));
    return 0;
}
