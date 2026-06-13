#include<stdio.h>

int fib(int n){
    if(n==1 || n==0){
        return n;
    }

    return fib(n-1) + fib(n-2);
}
int main(){
    int n;
    printf("Enter the size of sequence : ");
    scanf("%d", &n);
    int res = fib(n);
    printf("%d", res);
    
    return 0;
}