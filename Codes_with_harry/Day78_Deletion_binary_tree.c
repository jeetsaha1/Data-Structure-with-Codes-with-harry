#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void Inorder(struct Node *root){
    if(root!= NULL){
        Inorder(root->left),
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

int isBST(struct Node * root){
    static struct Node * prev = NULL;

    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }

        if (prev!= NULL && root->data <= prev->data)
        {
            return 0;
        }
        
        prev = root;
        return(isBST(root->right));
    }
    else
        return 1;
}

void insert(struct Node * root,int key){
    struct Node * prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key == root->data)
            return;
        else if(key < root->data)
            root = root->left;
        else   
            root = root->right;
    }

    struct Node * new = createNode(key);
    if(key < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

struct Node * inorderpredecessor(struct Node * root){   
    root = root->left;      //In order predeccessor is the most right node of the left subtree
    while(root->right!=NULL){
        root= root->right;
    }
    return root;
}

struct Node * deleteNode(struct Node * root, int value){
    struct Node * iPre;   // For taking the in Order Predecessor
    if(root==NULL){
        return NULL;
    }
    if(root->left ==  NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if (value< root->data)
        root->left= deleteNode(root->left , value);
    else if(value> root->data)
        root->right = deleteNode (root->right,value);
    else{
        iPre = inorderpredecessor(root);
        root->data = iPre ->data;
        root->left = deleteNode(root->left,iPre->data);
    }
    return root;
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
    // insert(p,23);
    Inorder(p);
    printf("\n%d\n",isBST(p));
    printf("\n");
    deleteNode(p,6);
    Inorder(p);
    return 0;
}