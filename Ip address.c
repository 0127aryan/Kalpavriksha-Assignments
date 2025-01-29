// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<stdbool.h>
bool isvalidLength(char *IP,int length){
     if(length>15){
        printf("max string length is 15");
        return false;
    }
    return true;
}
bool white_space(char *IP,int length){
     bool space=false;
    for(int index=0;index<length;index++){
        if(IP[index]==' '){
            printf("no whitespaces");
            space=true;
            break;
        }
    }
    if(space){
        return false;
    }
    return true;
}
bool validate(char *IP,int length){
     int dot=0;
    bool isvalid=true;
    for(int index=0;index<length;index++){
        if(IP[index]=='.' && index<length-1){
            dot++;
            if(IP[index+1]=='.'){
                isvalid=false;
                break;
            }
        }
        else if(IP[index]>='0' && IP[index]<='9'){
            continue;
        }
        else{
            isvalid=false;
            break;
        }
    }
     if(dot!=3 || !isvalid){
        
        return false;
    }
    if(!isvalid){
        return false;
    }
   return true;
}
bool Number(char *IP,int length){
    bool isvalid=true;
     for(int index=0;index<length;index++){
        if(IP[index]=='0' && IP[index+1]>='0' && IP[index+1]<='9'){
            isvalid=false;
            break;
        }
        else if(IP[index]>='0' && IP[index]<='9'){
            int number=0;
            while(index<length && IP[index]>='0' && IP[index]<='9'){
             number=number*10+IP[index]-'0';
             index++;
            }
            if(number>=0 && number<=255){
            }
            else{
                isvalid=false;
                break;
            }
        }
    }
    
    if(!isvalid){
        return false;
    }
   return true;
}
void solve(char *IP,int length){
   bool lengthValidation=isvalidLength(IP,length);
   bool isSpace=white_space(IP,length);
   bool isDot_or_ischaracter=validate(IP,length);
   bool isvalidNumber=Number(IP,length);
   if(lengthValidation && isSpace && isDot_or_ischaracter && isvalidNumber){
       printf("Valid");
   }
   else{
       printf("Invalid");
   }
}
int main() {
     char *IP;
     printf("Enter IP address:");
     scanf("%s",IP);
     int length=strlen(IP);
     solve(IP,length);

    return 0;
}