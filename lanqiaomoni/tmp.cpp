#include <iostream>
using namespace std;

// ...冲突记录: Compact[i][j]=false代表点数为i的面与点数为j的面存在冲突
bool Compact[7][7];

// ...Parner[i]=j代表 点数为i的面 的对立面点数为j
const int Parner[7] = {0, 4, 5, 6, 1, 2, 3};
const long long MOD = 1000000007;

int main(int argc, char **argv)
{
    long long N; // 骰子高度
    int M;       // 冲突组数
    int s1, s2;
    cin >> N >> M;
    for (int i = 0; i < 7; ++i)
        for (int j = 0; j < 7; ++j)
            Compact[i][j] = true;

    for (int i = 0; i < M; ++i)
    {
        cin >> s1 >> s2;
        // ...点数为s1的面与点数为s2的面存在冲突
        Compact[s1][s2] = Compact[s2][s1] = false;
    }
    long long dp[2][7]; // 滚动数组
    long long C = 4;
    int e = 0; // 滚动标志
    for (int i = 1; i < 7; ++i)
        dp[e][i] = 1;

    // dp[i][j]代表高度为i的,顶面点数为j的叠骰子方案数
    // 在这里忽略每个骰子可以四面转向的情况, 把该情况留到最后乘上去就可以了
    int j, k;
    for (long long i = 2; i <= N; ++i)
    {
        e = 1 - e; // ...滚动处理
        C = (C * 4) % MOD;
        for (j = 1; j < 7; ++j)
        {
            dp[e][j] = 0;
            for (k = 1; k < 7; ++k)
                if (Compact[Parner[j]][k])
                    dp[e][j] += dp[1 - e][k];
            dp[e][j] %= MOD;
        }
    }
    int sum = 0;
    for (int i = 1; i < 7; ++i)
        sum = (sum + dp[e][i]) % MOD;
    sum = (sum * C) % MOD;
    cout << sum;
    return 0;
}