#include<stdio.h>
#define N 3 

int main() {
    int a[N][N];
    int x;
    int found = 0;
    printf("Enter the number to find in the matrix");
    scanf("%d", &x);
    
    printf("\nEnter the elements of matrix:");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j = 0;j<N;j++){
        if(a[i][j] == x){
            found = 1;
            break;}
        }
        if(found) break;
        if(found){
            
        }
        }
        
        if(found){
            printf("%d is found in array",x);
        }
        else{
            printf("%d is not found in the array",x);
        }
}
