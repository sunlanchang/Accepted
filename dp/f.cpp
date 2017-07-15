#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int dp[1010][1010];
int value[1010];
int volume[1010];

void init(int num_bone, int max_v)
{
    // for (int i = 0; i <= num_bone; i++)
    // {
    //     for (int j = 0; j <= max_v; j++)
    //     {
    //         dp[i][j] = 0;
    //     }
    // }
    memset(dp, 0, sizeof(dp));
    // memset(value, 0, sizeof(value));
    // memset(volume, 0, sizeof(volume));
}

int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        int num_bone, max_v;
        scanf("%d%d", &num_bone, &max_v);
        init(num_bone, max_v);
        for (int i = 1; i <= num_bone; i++)
        {
            scanf("%d", &value[i]);
        }
        for (int i = 1; i <= num_bone; i++)
        {
            scanf("%d", &volume[i]);
        }
        for (int i = 1; i <= num_bone; i++)
        {
            for (int j = 0; j <= max_v; j++)
            {
                if (j >= volume[i])
                {
                    dp[i][j] = max(dp[i - 1][j - volume[i]] + value[i], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
                // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + val[i]);
            }
        }
        // for (int i = 0; i <= num_bone; i++)
        // {
        //     for (int j = 0; j <= max_v; j++)
        //     {
        //         cout << dp[i][j] << "   ";
        //     }
        //     cout << "\n";
        // }
        cout << dp[num_bone][max_v] << "\n";
    }
    return 0;
}