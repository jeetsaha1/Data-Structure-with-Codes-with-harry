//Find the minimum and maximum element

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
    n->right = NULL;

    return n;
}

struct Node * inorder(struct Node * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int isBST(struct Node * root){
    struct Node * prev = NULL;
    if(root!= NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev= root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int min(struct Node * root){
    while(root->left!= NULL){
        root= root->left;
    }
    return root->data;
}

int max(struct Node * root){
    while(root->right!= NULL){
        root= root->right;
    }
    return root->data;
}

int main(){
    struct Node * p = createNode(5);
    struct Node * p1 = createNode(2);
    struct Node * p2 = createNode(7);
    struct Node * p3 = createNode(1);
    struct Node * p4 = createNode(3);
        
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inorder(p);
    printf("\nThe maximum element is : %d\n",max(p));
    printf("The minimum element is : %d\n",min(p));
    return 0;
}