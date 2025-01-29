#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int implement_atoi(char *ans){
    int length=strlen(ans);
    int number=0;
    int sign=0;   //for positive
    for(int index=0;index<length;index++){
        if(ans[index]=='-'){
            sign=1; //for negative;
        }
        else if(ans[index]>='0' && ans[index]<='9'){
        number=number*10+(ans[index]-'0');
        }
        else{
            return 0;
        }
    }
    if(sign){
        return -number;
    }
    return number;
}
int main() {
    // Write C code here
    // printf("Try programiz.pro");
      char *ans=(char*)malloc(100*sizeof(char));
      printf("Enter string:");
      scanf("%s",ans);
    int number=implement_atoi(ans);
    printf("Number is:%d",number);

    return 0;
}