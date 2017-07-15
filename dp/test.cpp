#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_SIZE = 1005;

int a[MAX_SIZE];  //存储输入
int dp[MAX_SIZE]; //a[0..i]的最长递增子序列的长度

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1; //初始化为1，方便以下处理
        /*动态规划*/
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }

    cout << *max_element(dp, dp + n) << endl;

    return 0;
}