#include <stdio.h>
#define ROWS 3 
#define COLS 3

int main()
{
    int a[ROWS][COLS];
    for(int i =0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Matrix entered is:\n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
    int frequency[100] = {0};
    for(int i = 0;i<ROWS;i++){
        for(int j = 0;j<COLS;j++){
            int num = *(*(a+i)+j);
            
            if(num >=1 && num <=100){
                frequency[num]++;
            }
        }
    }
    
    printf("Frequency for each number:\n ");
    for(int i=0;i<100;i++){
        if(frequency[i] > 0){
            printf("%d -> %d times\n",i,frequency[i]);
        }
    }
    
    return 0;
    
}
