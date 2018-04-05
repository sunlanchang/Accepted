#include <cstdio>
int main()
{
    freopen("in.txt", "r", stdin);
    int sum2 = 0, sum5 = 0, n;
    while (~scanf("%d", &n))
    {
        int tmp = n;
        while (n % 2 == 0)
            sum2++, n /= 2;
        while (tmp % 5 == 0)
            sum5++, tmp /= 5;
    }
    printf("%d\n", sum5 < sum2 ? sum5 : sum2);
    return 0;
}