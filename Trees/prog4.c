//height of tree

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

int max(int a, int b){
    return (a>b)?a:b;
}

int tree_height(struct Node * root){
    int sum,left_count,right_count,left=0, right=0;
    if(root == NULL){
        return 0;
    }
    else{
        left_count = tree_height(root->left);
        left += left_count;
        right_count = tree_height(root->right);
        right += right_count;
    }
    return 1+max(left,right);
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
    printf("The height of the tree is %d",tree_height(p));
    return 0;
}
