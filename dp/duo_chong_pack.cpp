#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Facility
{
    int value;
    int number;
};

Facility facility[50000];
int dp[50000];

void init(int N)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        facility[i].value = 0;
        facility[i].number = 0;
    }
}

int main()
{
    int N;
    while (scanf("%d", &N) && N != -1)
    {
        init(N);
        int sum_value = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d%d", &facility[i].value, &facility[i].number);
            sum_value += facility[i].value * facility[i].number;
        }
        for (int i = 1; i <= N; i++)
        {
            for (int k = 1; k <= facility[i].number; k++)
            {
                for (int j = sum_value / 2; j >= facility[i].value; j--)
                {
                    dp[j] = max(dp[j], dp[j - facility[i].value] + facility[i].value);
                }
            }
        }
        int t1 = dp[sum_value / 2];
        int t2 = sum_value - t1;
        if (t1 >= t2)
        {
            cout << t1 << " " << t1 << "\n";
        }
        else
        {
            cout << t2 << " " << t1 << "\n";
        }
    }
    return 0;
}