#include <cstdio>
int arr[300];
int main()
{
    int m, n;
    while (~scanf("%d%d", &m, &n))
    {
        int len = 1;
        if (m < 0)
            printf("-");
        m = (m > 0 ? m : -m);
        while (m != 0)
            arr[len++] = m % n, m /= n;
        for (int i = len - 1; i >= 1; i--)
            if (arr[i] >= 10)
                printf("%c", arr[i] % 10 + 'A');
            else
                printf("%d", arr[i]);
        printf("\n");
    }
    return 0;
}
