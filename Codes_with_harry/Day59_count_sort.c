#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

//To find the maximum element so that the length of the array is located effectively.
int maximum(int arr[],int num){
    int max =INT_MIN;
    
    for (int i = 0; i < num; i++)
    {
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int arr[], int num){
    int max = maximum(arr, num);//initialize the length for traversing

    //initialize the counter array
    int *count = (int*)malloc((max+1)*sizeof(int));

    //Initialize the all spaces of the counter variable
    for (int i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    //match the all elements with the index of counter variable 
    for (int i = 0; i < num; i++)
    {
        count[arr[i]] = count[arr[i]]+1; 
    }

    //i = counter for count arraay
    //j = counter for given array    
    int i = 0, j = 0;

    //Rearrange the array from the counter array
    while (i<=max)
    {
        if (count[i]>0)
        {
            arr[j] = i;
            count[i] = count[i]-1;
            j++;
        }
        else{
            i++;
        }
        
    }
    

}

int main(){
    int num;
    printf("Enter the length of the array : ");
    scanf("%d",&num);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    count_sort(arr,num);

    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}