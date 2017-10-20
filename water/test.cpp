#include <stdio.h>
int f[7654][543];
int main()
{
    f[0][0] = 1;
    f[1][0] = 1;
    f[2][0] = 1;
    f[3][0] = 1;
    for (int i = 4; i < 7654; i++)
    {
        int k = 0;
        for (int j = 0; j < 543; j++)
        {
            k += f[i - 4][j] + f[i - 3][j] + f[i - 2][j] + f[i - 1][j];
            f[i][j] = k % 10000;
            k /= 10000;
        }
    }
    int n;
    while (~scanf("%d", &n))
    {
        int i = 543 - 1;
        while (f[n][i] == 0 && i >= 0)
            i--; //去前置0
        printf("%d", f[n - 1][i]);
        for (int j = i - 1; j >= 0; j--)
            printf("%04d", f[n - 1][j]);
        printf("\n");
    }
    return 0;
}