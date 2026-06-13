#include<stdio.h>
#include <stdbool.h>

bool check(int n){
    int s = 0;
    int x,r;
    x = n;
    while (x > 0)
    {
        r = x % 10;
        x = x / 10;
        s = s + r * r * r;
    }

    return n==s;
       
}
int main(){

    int n;
    printf("Enter Range :");
    scanf("%d", &n);

    for(int i = 1;i<=n;i++){
        if(check(i)==true){
            printf("%d, ", i);
        }
    }
    
    return 0;
}