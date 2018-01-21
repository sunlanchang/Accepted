#include <stdio.h>
#include <string.h>
#define N 100
long long f[N];
int n;
int main(void)
{
    //只有最初的母牛生小牛,最初的母牛。
    f[1] = 1, f[2] = 2, f[3] = 3, f[4] = 4;
    //第i年的牛数等于i-1年的牛数加上i-3年的牛数，i-3年到第i年正好四年，第i-3年的牛都会在第i年生一头牛， 所以加上f[i-3]。
    //从第五年有小牛开始生小牛。
    for (int i = 5; i < N; i++)
        f[i] = f[i - 1] + f[i - 3];
    while (scanf("%d", &n), n)
        printf("%lld\n", f[n]);
    return 0;
}