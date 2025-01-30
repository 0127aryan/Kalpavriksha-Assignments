#include<stdio.h>
#include<stdlib.h>

int printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int bubbleSort(int *arr, int n){
    int temp;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }
        }
    }

}

int main(){
    int n;
    printf("enter the length of array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array entered is:");
    printArray(arr,n);
    bubbleSort(arr,n);
    printf("sorted array is:");
    printArray(arr,n);
    return 0;
}