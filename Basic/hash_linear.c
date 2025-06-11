//Hashing with linear probing

#include<stdio.h>
#include<stdlib.h>

//At first make a hash table for constructing the hash.
struct hash_table{
    int size;
    int *arr;
};

//Initialize the array of the empty array of the structure with zero.
void init(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}

//Declare the function for the operation
struct hash_table * hash_function(int *arr1, int n){   //n is the size of the array

    //Dynamic memory allocation
    struct hash_table * h = (struct hash_table*)malloc(sizeof(struct hash_table));
    h->arr = (int*)malloc(h->size*sizeof(int));
    h->size =10;

    int i = 0;              // for iteration
    int hash_value;         //for iterating the elements according to the structure of the array
    init(h->arr,h->size);   //initialize all of the spaces of the array with 0

    while(i<n){
        hash_value = arr1[i]%h->size;               //R(k) = k mod n

        if(h->arr[hash_value]!=0){      
            hash_value = (hash_value+1)%h->size;    //R'(k,i) = (R(k)+i)mod n
        }

        h->arr[hash_value]  = arr1[i];
        i++;
        
    }
   return h;
}

void print_element(struct hash_table *h){
     for (int i = 0; i < h->size; i++)            //For printing the element of the hash
    {
        printf("%d : %d\n",i,h->arr[i]);
    }
}

void search_element(struct hash_table * h,int val){
    for (int i = 0; i < h->size; i++)
    {
        if(val == h->arr[i])
            printf("The element is found");
        else    
            printf("The element is not found");
    }
    
}

void delete_element(struct hash_table * h,int val){
    for (int i = 0; i < h->size; i++)
    {
        if(val == h->arr[i]){
            h->arr[i] = 0;
            printf("The element is deleted");
        }
        else
            continue;
    }
    
}
int main(){
    //Initialize the array
    printf("\nEnter the ten elements : \n");
    int arr[10] ;
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    
    struct hash_table * h = hash_function(arr,10);

    print_element(h);
    delete_element(h,arr[4]);
    print_element(h);
    return 0;
}