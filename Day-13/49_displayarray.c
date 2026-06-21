#include <stdio.h>

int main(){
int arr[100], i, n;
printf("enter the number of elements:");
scanf("%d", &n);
printf("enter the %d elements:\n", n);
      for(i=0;i<n;i++)
{
    scanf("%d", &arr[i]);
}
printf("Array elements are:\n");
      for(i=0;i<n;i++)
      {
    printf("%d", arr[i]);
} 
return 0;
}