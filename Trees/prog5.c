//Mirror a Binary Tree

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    n->left = NULL;
    n->right=  NULL;

    return n;
}

struct Node * inorder(struct Node * root){
    if(root!=NULL){
        
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct Node * mirror(struct Node*root){
    struct Node * left;
    struct Node * right;
    if(root == NULL){
        return NULL;
    }
    else{
        left = root->left;
        right = root->right;
        root ->left = right;
        root->right = left;
        if(root->right == NULL){
            mirror(root->left);
        }else{
            mirror (root->right);
        }
    }
    return root;
}

int main(){
    struct Node * p = createNode(5);
    struct Node * p1 = createNode(2);
    struct Node * p2 = createNode(7);
    struct Node * p3 = createNode(1);
    struct Node * p4 = createNode(3);
    struct Node * p5 = createNode(6);
    struct Node * p6 = createNode(8);


    //      5                 5
    //    /  \              /  \
    //   2    7      -->   7    2
    //  / \  / \          / \  / \
    // 1   3 6  8        8   6 3  1           

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p2->left = p6;

    inorder(p);
    mirror(p);
    printf("\n");
    inorder(p);
    return 0;
}