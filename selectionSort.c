#include<stdio.h>
#include<stdlib.h>

int printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr,n);
    printf("sorted array is:");
    printArray(arr,n);
    return 0;
}