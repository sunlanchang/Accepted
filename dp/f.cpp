#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int value[1005] = {0};
int volume[1005] = {0};
int dp[1000005] = {0};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(value, 0, sizeof(value));
        memset(volume, 0, sizeof(volume));
        memset(dp, 0, sizeof(dp));
        int n, v;
        cin >> n >> v;
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> volume[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = v; j >= volume[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - volume[i]] + value[i]);
            }
        }
        cout << dp[v] << endl;
    }
    return 0;
}