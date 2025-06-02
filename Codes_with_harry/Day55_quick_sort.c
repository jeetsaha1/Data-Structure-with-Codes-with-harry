#include<stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j =high;
    int temp;

    do{
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }
        
        if (i<j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int arr[], int low, int high){
    int partition_idx;

    if(low<high)
    {
        partition_idx = partition(arr,low,high);
        quick_sort(arr, low ,partition_idx-1);
        quick_sort(arr,partition_idx+1,high);
    }
    
}



int main(){
    int num;
    printf("Enter the number of elements : ");
    scanf("%d",&num);
    int arr[num];
    //input the element of the array
    for (int i = 0; i < num; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    quick_sort(arr,0,num-1);
    
    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}