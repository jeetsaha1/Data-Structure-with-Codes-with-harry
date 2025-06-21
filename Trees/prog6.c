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
int isBST(struct Node * root){
    if(root!=NULL){
        struct Node * prev = NULL;
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!= NULL && root->data<= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

struct Node * search(struct Node * root,int key){
    if(root== NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data >key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}


struct Node * inorder(struct Node * root){
    if(root!=NULL){
        
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
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
    printf("\n%d ",isBST(p));
    if(search(p,1))
        printf("The element is found");
    else
        printf("The element is not found");
    return 0;
}