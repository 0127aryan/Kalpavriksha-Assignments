/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<string.h>

int main()
{
    char str[100];
    scanf("%[^\n]%*c",str);
    printf("Entered string is: %s",str);
    int length = strlen(str);
    int count = 0;
    
    for(int i=0;i<length;i++){
        if(str[i] ==' '){
            count++;
        } 
        
    }
    count = count + 1;
    
    printf("\nNumber of words are:%d",count);
}
