#include <stdio.h>
#include<string.h>

int main()
{
    char str1[10],str2[10];
    char found = 0;
    char temp[40];
    
    scanf("%s %s",str1,str2);
    printf("%s %s", str1,str2);
    
    if(strlen(str1) != strlen(str2)){
        printf("false");
    } 
    else{
        strcpy(temp,str1);
        strcat(temp,str1);
        printf("\n%s",temp);
    }
    
    if(strstr(temp,str2) != NULL){
        found = 1;
    }
    
    if(found){
        printf("\ntrue");
    }
    else{
        printf("\nfalse");
    }
    
    return 0;
}
    
