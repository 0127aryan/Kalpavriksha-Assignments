/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<string.h>

void removeDuplicate(char *str){
    int length = strlen(str);
    int seen[256] = {0};
    int resultIndex = 0;
    
    for(int i=0;i<length;i++){
        char currentChar = str[i];
        
        if(seen[currentChar] == 0){
        str[resultIndex++] = currentChar;
        seen[currentChar] =1;
    }
    }
    
    str[resultIndex] = '\0';
    
    
}

int main()
{
    char str[100];
    
    printf("Enter a string:\n");
    scanf("%s",str);
    
    removeDuplicate(str);
    
    printf("\n%s",str);
    
    return 0;
}
