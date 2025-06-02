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

struct Node * Inorder(struct Node * root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
       
    }
}

int isBST(struct Node * root){
    static struct Node * prev =NULL;
    if (root!=NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);if (!(isBST(root->left)))
    {
        return 0;
    }
    if (prev!=NULL && root->data <= prev->data)
    {
        return 0;
    }
    }
    else
        return 1;
}

struct Node * searchIter(struct Node * root, int key){
    while(root!=NULL){
        if(key == root->data)
            return root;
        else if(key < root->data)
            root = root->left;
        else
        root = root->right;
    }
    return NULL;
}

int main(){
    //Constructing the real node - using function 
    struct Node * p = createNode(5);
    struct Node * p1 = createNode(3);
    struct Node * p2 = createNode(6);
    struct Node * p3 = createNode(1);
    struct Node * p4 = createNode(4);


    //Finally the tree looked like this:
    //       5
    //      / \
    //     3   6
    //    / \
    //   1   4


    //Linking the root with the left and the right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    Inorder(p);
    printf("\n%d\n",isBST(p));
    if(searchIter(p,4)){
        printf("The element is found.");
    }
    else
        printf("The element is not found.");
    return 0;
}

