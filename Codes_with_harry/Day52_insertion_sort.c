#include<stdio.h>

//Function of insertion sort

int insertion_sort(int arr[], int n){
    for (int i = 1; i < n-1; i++)
    {
        int temp = arr[i];         // taka a temp variable to move through the loop
        int j = i-1;               // For sorted array

        while (j>= 0 && arr[j]> temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
}

int main(){
    //At first input the number of the array.
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    int arr[num];
    //Input of the array
    for (int i = 0; i < num; i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    insertion_sort(arr,num);
    //Print the sorted array
    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}