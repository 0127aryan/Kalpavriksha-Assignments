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
    char ch[20];
    char x;
    scanf("%s\n",ch);
    printf("string entered is:%s\n",ch);
    printf("enter the letter to be removed:\n");
    scanf("%c",&x);
    
    int count = 0;
    int j = 0;
    
    int length = strlen(ch);
    for(int i=0;i<length;i++){
        if(ch[i]!=x){
            ch[j++] = ch[i];
        }
    }
    ch[j] = '\0';
    
    printf("%s",ch);

    return 0;
}
