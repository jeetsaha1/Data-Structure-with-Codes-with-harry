#include<stdio.h>

void Merge(int arr[], int low, int mid ,int high){
    int i = low;
    int j =mid+1;
    int k = 0;

    int temp[high-low+1];

    while (i<=mid && j<=high)
    {
        if (arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
            temp[k++] = arr[j++];
    }
    

    while (i<=mid)
    {
        temp[k++] = arr[i++];
    }
    
    while (j<=high)
    {
        temp[k++] = arr[j++];
    }

    for (int g = 0; g < k; g++)
    {
        arr[low+g] = temp[g];
    }
    
    
}


void Merge_sort(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        Merge_sort(arr,low,mid);
        Merge_sort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}

int main(){
    int num;
    printf("Enter the length of the number : ");
    scanf("%d",&num);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    Merge_sort(arr,0,num-1);

    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}