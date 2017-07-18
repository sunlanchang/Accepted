#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 300010;
int dp[N];
int v[110], num[110];
int n;
void ZeroOnePack(int w, int v, int W)
{
    for (int i = W; i >= w; i--)
        dp[i] = max(dp[i], dp[i - w] + v);
}
void CompletePack(int w, int v, int W)
{
    for (int i = w; i <= W; i++)
        dp[i] = max(dp[i], dp[i - w] + v);
}
void MultiplePack(int w, int v, int num, int W)
{
    if (w * num >= W)
        CompletePack(w, v, W);
    else
    {
        int k = 1;
        while (k <= num)
        {
            ZeroOnePack(k * w, k * v, W);
            num -= k;
            k *= 2;
        }
        ZeroOnePack(num * w, num * v, W);
    }
}
int main()
{
    while (scanf("%d", &n), n >= 0)
    {
        int W = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &v[i], &num[i]), W += v[i] * num[i];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++)
            MultiplePack(v[i], v[i], num[i], W / 2);
        int a = dp[W / 2], b = W - a;
        if (a < b)
            swap(a, b);
        printf("%d %d\n", a, b);
    }
    return 0;
}