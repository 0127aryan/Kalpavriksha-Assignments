#include <stdio.h>

int main()
{
   int a[3][3] = {{1,2,3}, {4,10,6}, {7,8,9}};
   int n = sizeof(a)/sizeof(a[0]);
   int sum =0;
   int b = 0;
   
   for(int i =0;i<n;++i){
       for(int j=0;j<n;++j){
           printf("%d ", a[i][j]);
       }
       printf("\n");
   }
   
   for(int i=0;i<n;++i){
       
           sum = sum + a[i][i];
           b = b + a[i][n-i-1-n];
           
       
   }
   
   printf("%d\n",n);
   printf("%d\n",sum);
   
   printf("%d\n",b);
   printf("Total sum of diagonals is:%d",sum+b);
}
