#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int wei[1010]; //重量==价值
int dp[1010][1010];
int max(int x, int y)
{
    if (x >= y)
    {
        return x;
    }
    else
        return y;
}

int main()
{
    int n, i, j, ians;
    while (scanf("%d", &n) && n)
    {
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &wei[i]);
        }
        sort(wei + 1, wei + n + 1);
        scanf("%d", &ians); //卡余额
        if (ians < 5)
        {
            cout << ians << "\n";
            continue;
        }
        for (i = 1; i <= n - 1; i++)
        {
            for (j = 0; j <= ians - 5; j++)
            {
                if (j >= wei[i])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wei[i]] + wei[i]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        cout << ians - dp[n - 1][ians - 5] - wei[n] << "\n";
    }
    return 0;
}