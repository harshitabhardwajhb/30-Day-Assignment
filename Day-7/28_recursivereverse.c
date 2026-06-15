#include <stdio.h>
int reverseNum(int n,int rev){
    if(n==0){
        return rev;
    }
    else
    return reverseNum(n/10,rev*10+n%10);
}
int main(){
    int num;
    printf("enter num:");
    scanf("%d",&num);
    printf("%d",reverseNum(num,0));
    return 0;
}