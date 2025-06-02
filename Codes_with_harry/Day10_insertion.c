#include<stdio.h>
//For traversing
int display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
//For insertion
int indinsertion(int arr[], int size, int insert_element, int capacity, int index){
    if (size>=capacity)
    {
        return -1;
    }
    
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=insert_element;
    return 1;
}

int main(){
    int arr[100] = {7,8,10,27,88};
    int size = 5, insert_element = 45, index =3;
    display(arr,size);
    indinsertion(arr, size, insert_element, 100, index);
    size+=1;
    printf("\n");
    display(arr, size);
    return 0;
}