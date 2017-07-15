#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[1002][1002];
int value[1002], w[1002];
int N, V;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> V;
        for (int i = 1; i <= N; i++)
            cin >> value[i];
        for (int i = 1; i <= N; i++)
            cin >> w[i];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++)
            for (int j = 0; j <= V; j++)
            {
                if (w[i] <= j)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + value[i]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        cout << dp[N][V] << endl;
    }
    return 0;
}
