#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
int length(char *str){
    int index=0;
    while(str[index]!='\0'){
        index++;
    }
    return index;
}
bool solve(char *str1,char *str2){
    int length1=length(str1);
    int length2=length(str2);
    int count1[124]={0};
    int count2[124]={0};
    for(int index=0;index<length1;index++){
        int value=(int)str1[index];
        count1[value]++;
    }
    for(int index=0;index<length2;index++){
        int value=(int)str2[index];
        count2[value]++;
    }
    for(int index=0;index<124;index++){
        if(count1[index]==count2[index]){
            continue;
        }
        else{
        return false;
        }
    }
 return true;
}
int main() {
    printf("Enter string1:");
    char *str1=(char*)malloc(100*sizeof(char));
    scanf("%[^\n]",str1);
    printf("Enter string2:");
    char *str2=(char*)malloc(100*sizeof(char));
    scanf("\n");
    scanf("%[^\n]",str2);
    if(solve(str1,str2)){
        printf("true");
    }
    else{
        printf("false");
    }

    return 0;
}