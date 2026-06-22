#include <stdio.h>
int main()
{
    int n, i, el, cnt = 0, arr[100];
    printf("enter number of elements");
    scanf("%d", &n);
    printf("enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }
    printf("enter the element to find frequency:");
    scanf("%d", &el);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == el)
            cnt++;
    }
    printf("frequency of %d element is %d", el, cnt);
    return 0;
}