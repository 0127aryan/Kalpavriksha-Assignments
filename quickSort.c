#include<stdio.h>
#include<stdlib.h>

int printArray(int *a, int n){
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[low];

    while(i<j){
        while(i<high && arr[i]<=pivot){
            i++;
        }
        while(j>low && arr[j]>=pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quickSort(int a[], int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);

         quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    
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
    quickSort(arr,0,n-1);
    printf("sorted array is:");
    printArray(arr,n);
    return 0;
}