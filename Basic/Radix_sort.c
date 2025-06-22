//Radix sort

#include<stdio.h>
#include<stdlib.h>

int maximum(int arr[],int n){
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] >max){
            max = arr[i];
        }
    }
    return max;
    
}

void count_sort(int arr[], int n,int pos){
    int max = maximum(arr,n);

    int *count = (int*)calloc(max+1,sizeof(int));   //Initialize the count array with calloc for initializing every space with 0
    int *output = (int*)malloc(n*sizeof(int));      //For the result same size as input array

    //Count frequencies
    for (int i = 0; i < n; i++)      
    {
        int digit = (arr[i]/pos)%10;  
        count[digit]++;
    }
    
    //Cumulative frequency
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i-1];         
    }
    
    //For result
    for (int i = n-1; i >=0  ; i--)
    {
       int digit = (arr[i] / pos) % 10;
        output[--count[digit]] = arr[i];
    }

    //Coping the result in the input array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];                    
    }
    

}

void radix_sort(int arr[], int n){
    int max = maximum(arr,n);

    for (int pos = 1; max/pos >0; pos*=10)
    {
        count_sort(arr,n,pos);
    }
    
}

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    
    for (int  i = 0; i < n; i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    radix_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}


// void count_sort(int arr[], int n){
//     int max = maximum(arr,n);

//     int *count = (int*)calloc(max+1,sizeof(int));   //Initialize the count array with calloc for initializing every space with 0
//     int *output = (int*)malloc(n*sizeof(int));      //For the result same size as input array

//     //Count frequencies
//     for (int i = 0; i < n; i++)         
//     {
//         count[arr[i]]++;
//     }
    
//     //Cumulative frequency
//     for (int i = 1; i <= max; i++)
//     {
//         count[i] += count[i-1];         
//     }
    
//     //For result
//     for (int i = n-1; i >=0  ; i--)
//     {
//         output[--count[arr[i]]] = arr[i];     
//     }

//     //Coping the result in the input array
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = output[i];                    
//     }
    

// }