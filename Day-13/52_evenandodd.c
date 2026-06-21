#include <stdio.h>
int main()
{
    int n, i;
    int evenCount = 0, oddCount = 0;
    printf("enter n:");
    scanf("%d", &n);
    int arr[n];
    printf("enter the %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
    printf("even elements=%d\n", evenCount);
    printf("odd elements=%d\n", oddCount);
    return 0;
}