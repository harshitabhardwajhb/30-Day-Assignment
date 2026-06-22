#include <stdio.h>
int main()
{
    int i, j, n, arr[100];
    printf("enter number of elements");
    scanf("%d", &n);
    printf("enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("duplicates elements are:\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d", arr[i]);
                break;
            }
        }
    }
    return 0;
}