#include<stdio.h>
#include<stdlib.h>

void minMax(int arr[],int len,int *min, int *max){
    *min = *max = arr[0];
    for(int i=1;i<len;i++){
        if (arr[i]< *max){
            *max = arr[i];
        } if(arr[i]>*min){
            *min=arr[i];
        }
    }
}

int main() {
     int a[] = {23,34,5,66,78,345,234,11,3456,78,458,98,36,54,1234,223};
     int max,min;
     int length = sizeof(a)/sizeof(a[0]);
     minMax(a,length,&max,&min);
     printf("Max element is %d and min element is %d",max,min);
     return 0;
}