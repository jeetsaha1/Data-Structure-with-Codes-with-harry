#include<stdio.h>

int selection_sort(int arr[], int num){
    for (int i = 0; i < num-1; i++)
    {
        int min = i;
        for (int j = i+1; j < num; j++)
        {
            if (arr[j]<arr[min])
            {
                min = j;
            }
            
        }
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    
}


int main(){
    int num;
    printf("Enter the number of inputs : ");
    scanf("%d",&num);
    int arr[num];

    for (int i = 0; i < num; i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    selection_sort(arr,num);

    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
    return 0;
}