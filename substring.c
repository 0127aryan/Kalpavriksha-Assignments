#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int solve(char *str1,char *str2){
    int length1=strlen(str1);
    int length2=strlen(str2);
   int index=-1;
   int index2=0;
   for(int index1=0;index1<length1;index1++){
       if(str1[index1]==str2[index2]){
           int str1_index=index1+1;
           int str2_index=index2+1; 
           bool isfound=false;
           while(str1_index<length1 && str2_index<length2){
               if(str1[str1_index]==' ' && str2[str2_index]==' '){
                   str1_index++;
                   str2_index++;
                   continue;
               }
              else if(str1[str1_index]==str2[str2_index]){
                   str1_index++;
                   str2_index++;
                   isfound=true;
               }
               else{
                   isfound==false;
                   break;
               }
           }
           if(isfound){
           if(str1_index==length1 && str2_index<length2){
               return -1;
           }
           else{
              index=index1;
              break;
           }
           }
           else{
               index=-1;
           }
       }
   }
   return index;
}
int main() {
    printf("Enter string1:");
    char *str1=(char*)malloc(100*sizeof(char));
    scanf("%[^\n]",str1);
    printf("Enter string2:");
    char *str2=(char*)malloc(100*sizeof(char));
    scanf("\n");
    scanf("%[^\n]",str2);
    int ans=solve(str1,str2);
    printf("index:%d",ans);

    return 0;
}