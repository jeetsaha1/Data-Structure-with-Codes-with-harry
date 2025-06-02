#include<stdio.h>
//For traversing
int display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
//For deletion
int indeletion(int arr[], int size, int index){
    for (int i = index; i <=size; i++)
    {
        arr[i]=arr[i+1];
    }
    return 1;
}

int main(){
    int arr[100] = {7,8,10,27,88};
    int size = 5, index =0;
    display(arr,size);
    indeletion(arr, size,index);
    size-=1;
    printf("\n");
    display(arr, size);
    return 0;
}