#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 100010;
int dp[MAX];
int a[MAX];
int left_index[MAX];
const int INF = 0x7fffff;

void init(int len)
{
    memset(dp, 0, sizeof(int) * (len + 10));
    memset(a, 0, sizeof(int) * (len + 10));
    memset(left_index, 0, sizeof(int) + 10);
}

int main()
{
    int T, cnt_T;
    scanf("%d", &T);
    cnt_T = T;
    while (cnt_T--)
    {
        int N, ans = -INF;
        scanf("%d", &N);
        init(N);
        left_index[0] = 1;
        dp[1] = 1;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &a[i]);
            if (dp[i - 1] >= 0)
            {
                dp[i] = dp[i - 1] + a[i];
                left_index[i] = left_index[i - 1];
            }
            else
            {
                dp[i] = a[i];
                left_index[i] = i;
            }
            ans = max(ans, dp[i]);
        }
        for (int i = 1; i <= N; i++)
        {
            if (dp[i] == ans)
            {
                printf("Case %d:\n", T - cnt_T);
                printf("%d %d %d\n", ans, left_index[i], i);
                if (cnt_T != 0)
                {
                    cout << "\n";
                }
                break;
            }
        }
    }
    return 0;
}