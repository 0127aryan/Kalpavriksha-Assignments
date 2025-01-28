#include<stdio.h>
#include<stdlib.h>

int linearSearch(int a[], int size, int element){
    for(int i=0;i<size;i++){
        if(a[i]==element){
            printf("%d\n",a[i]);
            return i;
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
    
    int search = linearSearch(arr, size, element);
    printf("Element %d found at index %d\n", element, search);
}