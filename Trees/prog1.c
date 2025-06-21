// 1. Create and Traverse a Binary Tree
// Problem: Write a C program to create a binary tree and perform:
// Inorder traversal
// Preorder traversal
// Postorder traversal

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

struct Node *  preorder(struct Node *root){
    if(root != NULL){
        printf("Element : %d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct Node *  postorder(struct Node *root){
    if(root != NULL){
        preorder(root->left);
        preorder(root->right);
        printf("Element : %d\n",root->data);
    }
}

struct Node *  inorder(struct Node *root){
    if(root != NULL){
        preorder(root->left);
        printf("Element : %d\n",root->data);
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

    printf("Displaying postorder traversal:\n");
    postorder(p);

    printf("Displaying inorder traversal:\n");
    inorder(p);
    return 0;
}
