#include <iostream>
const int N = 110;
using namespace std;
int n, m;

struct Rice
{
    int price;
    int weight;
    int number;
} rice[N];
int dp[N];
//完全背包
void CompletePack(int cost, int weight)
{
    for (int i = cost; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i - cost] + weight);
    }
}
//01背包
void ZeroOnePack(int cost, int weight)
{
    for (int i = n; i >= cost; i--)
    {
        dp[i] = max(dp[i], dp[i - cost] + weight);
    }
}

//多重背包
void MultiplePack(int cost, int weight, int number)
{
    //如果大于等于金额，就按完全背包处理（此时相当于不限定袋数）
    if (cost * number >= n)
    {
        CompletePack(cost, weight);
        return;
    }
    int k = 1;
    while (k < number)
    {
        ZeroOnePack(k * cost, k * weight);
        number -= k;
        k *= 2;
    }
    ZeroOnePack(number * cost, number * weight);
}

int main()
{
    int _case;
    scanf("%d", &_case);
    while (_case--)
    {
        scanf("%d%d", &n, &m);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &rice[i].price, &rice[i].weight, &rice[i].number);
        }
        for (int i = 0; i < m; i++)
        {
            MultiplePack(rice[i].price, rice[i].weight, rice[i].number);
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}