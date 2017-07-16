#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int dp[1010][1010];
vector<int> price;

void init()
{
    memset(dp, 0, sizeof(dp));
    // price.clear();
    vector<int>().swap(price);
    // price.shrink_to_fit();
}

int main()
{
    int num;
    while (scanf("%d", &num) && num)
    {
        int max_index = 0, max_ele = -1;
        init();
        price.push_back(0);
        for (int i = 1; i <= num; i++)
        {
            int tmp_price;
            scanf("%d", &tmp_price);
            price.push_back(tmp_price);
            if (price[i] > max_ele)
            {
                max_index = i;
                max_ele = price[i];
            }
        }
        price.erase(price.begin() + max_index);
        int money;
        scanf("%d", &money);
        if (money < 5)
        {
            cout << money << "\n";
            continue;
        }
        for (int i = 1; i <= num - 1; i++)
        {
            for (int j = 0; j <= money - 5; j++)
            {
                if (j >= price[i])
                {
                    dp[i][j] = max(dp[i - 1][j - price[i]] + price[i], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << money - dp[num - 1][money - 5] - max_ele << "\n";
    }
    return 0;
}