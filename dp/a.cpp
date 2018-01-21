#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int number[400][400];
int dp[400][400];

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            number[i][j] = 0;
            dp[i][j] = 0;
        }
    }
}

int main()
{
    int lines;
    while (scanf("%d", &lines) != EOF)
    {
        init(lines);
        for (int i = 1; i <= lines; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                scanf("%d", &number[i][j]);
                dp[i][j] = max(dp[i - 1][j] + number[i][j], dp[i - 1][j - 1] + number[i][j]);
            }
        }
        // for (int i = 0; i <= lines; i++)
        // {
        //     for (int j = 0; j <= i; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        int ans = 0;
        for (int i = 1; i <= lines; i++)
        {
            if (dp[lines][i] > ans)
            {
                ans = dp[lines][i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}