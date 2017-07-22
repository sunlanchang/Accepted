#include <iostream>
using namespace std;
int main()
{
    int n, dp[10008], a[10008];
    while (cin >> n)
    {
        int mx = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            dp[i] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            mx = max(dp[i], mx);
        }
        for (int i = 0; i < n; i++)
        {
            cout << dp[i] << " ";
        }
        cout << "\n"
             << mx << endl;
    }
}