#include<stdio.h>
#define N 3
int main() {
    int a[N][N];
    int temp;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("original matrix\n");
    for(int i=0;i<N;i++){
        for(int j =0;j<N;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    
    for(int i=0;i<N;i++){
        int start = 0;
        int end = N-1;
        while(start<end){
            temp = a[i][start];
            a[i][start] = a[i][end];
            a[i][end] = temp;
            start++;
            end--;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    
    
    
    
}