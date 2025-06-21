//Delete element on BST

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

struct Node * inOrderPredecessor(struct Node* root){
    root = root->left;
    if(root->right !=NULL){
        root = root->right;
    }
    return root;
}

struct Node * delete(struct Node * root,int key){
    struct Node * iPre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }


    if(key < root->data){
        root->left = delete(root->left, key);
    }
    else if(key > root->data){
        root->right = delete(root->right,key);
    }
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete(root->left,iPre->data);
    }
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
    delete(p,2);
    printf("\n");
    inorder(p);
    return 0;
}