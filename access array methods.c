#include<stdio.h>

#define ROWS 3 
#define COLS 3 

int main(){
    int arr[ROWS][COLS] = {{1,2,3},{4,5,6},{7,8,9}};
    
    printf("Access array using indices\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
    
    printf("access array using pointers\n");
        for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("*(arr[%d] + %d) = %d\n", i, j, *(arr[i] + j));
        }
    }
    
    printf("access 2d array as 1d array\n");
    for (int i = 0; i < ROWS * COLS; i++) {
        printf("arr[%d] = %d\n", i, *(arr[0] + i));
    }
}