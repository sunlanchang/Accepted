#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 15000;
int value[maxn];
double weight[maxn], dp[100000];
int N;
double W;

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%d", &W, &N);
        W = 1 - W;
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d%lf", &value[i], &weight[i]);
            weight[i] = 1 - weight[i];
            ans += value[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < N; i++)
            for (int j = 10010; j >= value[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - value[i]] * weight[i]);
            }
        for (int i = ans; i >= 0; i--)
        {
            if (dp[i] > W)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
