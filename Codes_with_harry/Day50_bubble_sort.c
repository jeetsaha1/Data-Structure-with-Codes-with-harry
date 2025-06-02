#include<stdio.h>
#include<stdlib.h>

int bubble_sort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
}

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        printf("Enter the elements %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
    for (int  i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
        
    }
    
    return 0;
}