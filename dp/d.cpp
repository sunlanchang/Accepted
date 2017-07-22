#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int dp[10000][10000];
const int INF = 0x7fffff;

void init(int len1, int len2)
{
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            dp[i][j] = 0;
        }
    }
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int len1 = s1.length(), len2 = s2.length();
        init(len1, len2);
        int ans = -INF;
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                ans = max(dp[i][j], ans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
