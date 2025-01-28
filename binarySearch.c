#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int size,int element){
    int low = 0; 
    int high = size-1;
    

    while(low<=high){
        int mid = (low+high)/2;
    if(arr[mid] == element){
        return mid;
    }
    
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return -1;
}

int main(){
    int n;
    int i=0;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    int size = sizeof(arr)/sizeof(arr[0]);
    int element;
    
    printf("Enter the elements of array:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&element);
    
    int search = binarySearch(arr, size, element);
    printf("Element %d found at index %d\n", element, search);

    return 0;
}