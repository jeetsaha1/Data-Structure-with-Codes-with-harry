#include<stdio.h>

int LinearSearch(int arr[],int size, int ele){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==ele)
        {
            return i;
        }
        
    }
    return 1;
}
int main(){
    int arr[]= {1,3,5,56,4,3,23,5,4,54634,56,34};
    int size =sizeof(arr)/sizeof(arr[0]);
    int searchidx = LinearSearch(arr, size, 4);
    printf("The element is found at index %d",searchidx);
    return 0;
}

//Binary search is done in previous sem