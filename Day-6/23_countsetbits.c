#include <stdio.h>
int main(){
    int num,count=0;
    printf("enter any number:");
    scanf("%d",&num);
    while(num>0){
        count+=num&1;
        num>>=1;
    }
    printf("number ofset bits=%d",count);
    return 0;
}