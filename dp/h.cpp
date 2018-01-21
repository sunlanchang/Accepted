#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;

int cost[2020];
int value[2020];
int dp[50050];

void init(int v)
{
    memset(cost, 0, sizeof(cost));
    memset(value, 0, sizeof(value));
    for (int i = 1; i <= v; i++)
    {
        dp[i] = -INF;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int M, V;
        scanf("%d%d", &M, &V);
        init(V);
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d", &cost[i], &value[i]);
        }
        dp[0] = 0;
        for (int i = 1; i <= M; i++)
        {
            for (int j = cost[i]; j <= V; j++)
            {
                if (j >= cost[i])
                {
                    dp[j] = max(dp[j - cost[i]] + value[i], dp[j]);
                }
            }
            // for (int i = 0; i <= N; i++)
            // {
            //     cout << dp[i] << " ";
            // }
            // cout << "\n";
        }
        if (dp[V] < 0)
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            cout << dp[V] << "\n";
        }
    }
    return 0;
}