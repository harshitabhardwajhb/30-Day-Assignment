#include <stdio.h>
#define MAX 10

int main(void) {
    int r, c, i, j;
    int a[MAX][MAX], b[MAX][MAX], diff[MAX][MAX];

    printf("Enter number of rows and columns (max %d %d): ", MAX, MAX);
    if (scanf("%d %d", &r, &c) != 2) {
        printf("Invalid input\n");
        return 1;
    }
    if (r <= 0 || c <= 0 || r > MAX || c > MAX) {
        printf("Invalid size (must be 1..%d)\n", MAX);
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            diff[i][j] = a[i][j] - b[i][j];

    printf("Difference of matrices (first - second):\n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j)
            printf("%d\t", diff[i][j]);
        printf("\n");
    }

    return 0;
}
