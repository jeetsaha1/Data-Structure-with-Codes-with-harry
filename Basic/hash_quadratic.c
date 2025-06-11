//Hashing with Quadratic probing

#include<stdio.h>
#include<stdlib.h>

//Making an hash table
struct hash_table{
    int *arr;
    int size;
};

//Initializing the hash array with 0
void init(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

//Making an hash function
struct hash_table * hash_function(int arr[], int n){

    //Dynamic memory alloction
    struct hash_table * h = (struct hash_table *)malloc(sizeof(struct hash_table));
    h->size = 10;
    h->arr = (int*)malloc(h->size*sizeof(int));

    int i = 0;              //For iterating the array

    init(h->arr,h->size);   //Initialize the hash array

    while (i<n)
    {
        int key = arr[i];
        int original_hash = key % h->size;          //R(k) = k mod n -> original hash

        int j =0;
        int index = original_hash;

        while (h->arr[index]  != 0 && j<h->size)    //If the space of the array is not empty
        {
            j++;
            index = (original_hash+ j*j)% h->size;  //R'(k,i) = R(k) + i^2-> implementing the index
        }
        
        if(j<h->size)                               //Checking the condition
            h->arr[index] = key;
        
        i++;
    }
    return h;
}

//For printing the element
void print_elememt (struct hash_table * h){
    printf("\nPrinting Element:\n");
    for (int i = 0; i < h->size; i++)
    {
        printf("%d : %d\n",i,h->arr[i]);
    }
}

//For searching any element within the array
void search_element(struct hash_table * h, int val){
    printf("Searching element ...");
    for (int i = 0; i < h->size; i++)
    {
        if(val == h->arr[i])
            printf("The element is found.");
        else
            printf("The element is not found");
    }
    
}

//For deleting any element within array
void delete_element(struct hash_table * h, int val){
    printf("deleting element ...");
    for (int i = 0; i < h->size; i++)
    {
        if(val == h->arr[i]){
            h->arr[i] = 0;
            printf("The elememt is deleted.");
        }
        else
            continue;
    }
}

int main(){
    //Initialize the array
    int arr[10];
    printf("Enter the 10 elements of the array ; \n");
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    //Main job..
    struct hash_table * ht = hash_function(arr,10);
    print_elememt(ht);

    return 0;
}