#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1000000;
int dp[MAX];
int a[MAX];
int num_sub[MAX];

void init(int len)
{
    // memset(dp, 0, sizeof(int) * (len + 10));
    for (int i = 0; i <= len; i++)
    {
        dp[i] = 1;
    }
    dp[0] = 0;
    memset(a, 0, sizeof(int) * (len + 10));
    memset(num_sub, 0, sizeof(int) * (len + 10));
}

int main()
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        init(num);
        for (int i = 1; i <= num; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= num; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (a[j] >= a[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        for (int i = 1; i <= num; i++)
        {
            cout << dp[i] << " ";
        }
    }
    return 0;
}