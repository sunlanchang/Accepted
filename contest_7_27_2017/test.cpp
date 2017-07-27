#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1000010;
const int M = 10010;
const double inf = 0x3f3f3f3f;
int value[N];
double dp[N], w[N];

int main()
{
    freopen("in.txt", "r", stdin);
    int n, t, ans;
    double s;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf %d", &s, &n);
        s = 1 - s, ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %lf", &value[i], &w[i]);
            w[i] = 1 - w[i], ans += value[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = M; j >= value[i]; j--)
            {
                dp[j] = max(dp[j - value[i]] * w[i], dp[j]);
            }
        }
        for (int i = ans; i >= 0; i--)
        {
            if (dp[i] > s)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}