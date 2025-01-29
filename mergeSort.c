#include<stdio.h>
#include<stdlib.h>

int printArray(int *a, int n){
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int b[], int c[], int m, int n){
    int i,j,k;
    i=j=k=0;

    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k] = a[i];
            i++;k++;
        }
        else{
            c[k] = b[j];
            j++;k++;
        }
    }
    while(i<m){
        c[k]=a[i];
        i++;k++;
    }
    while(j<n){
        c[k]=b[j];
        j++;k++;
    }
}

void mergeSort(int arr[], int n){
    if(n<2){
        return;
    }
    int mid = n/2;
    int left[mid];
    int right[n - mid];

    for(int i=0;i<mid;i++){
        left[i] = arr[i];
    }
    for(int i=mid;i<n;i++){
        right[i-mid] = arr[i];
    }
    mergeSort(left,mid);
    mergeSort(right, n-mid);

    merge(left,right,arr,mid,n-mid);
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
    mergeSort(arr,n);
    printf("sorted array is:");
    printArray(arr,n);
    return 0;
}