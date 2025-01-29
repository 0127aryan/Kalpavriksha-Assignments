#include<stdio.h>
#include<stdlib.h>

int printArray(int *a, int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertionSort(int *a, int n){
    int key,j;
    for(int i=0;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = key;
    }

}

int main() {
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
    insertionSort(arr,n);
    printf("sorted array is:");
    printArray(arr,n);
    return 0;
}