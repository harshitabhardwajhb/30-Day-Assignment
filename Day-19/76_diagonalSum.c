#include <stdio.h>
#define MAX 20

int main(void) {
    int n, i, j;
    int a[MAX][MAX];
    long long primary = 0, secondary = 0;

    printf("Enter number of rows and columns (square matrix, max %d): ", MAX);
    if (scanf("%d %d", &n, &n) != 2) {
        printf("Invalid input\n");
        return 1;
    }
    if (n <= 0 || n > MAX) {
        printf("Invalid size (must be 1..%d)\n", MAX);
        return 1;
    }

    printf("Enter matrix elements row-wise:\n");
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; ++i) {
        primary += a[i][i];
        secondary += a[i][n-1-i];
    }

    long long combined = primary + secondary;
    if (n % 2 == 1) combined -= a[n/2][n/2];

    printf("Primary diagonal sum = %lld\n", primary);
    printf("Secondary diagonal sum = %lld\n", secondary);
    printf("Combined (unique elements) diagonal sum = %lld\n", combined);

    return 0;
}
