#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Classes
{
    vector<int> stu;
    int sum;
};

Classes cls[1100];
int sum_cls, k_iq, number[10], n;
int ans;

void solve()
{
    int first = number[0], second = number[1];
    for (int i = 0; i < cls[first].stu.size(); i++)
    {
        for (int j = 0; j < cls[number[1]].stu.size(); j++)
        {
            int iq1 = cls[first].stu[i], iq2 = cls[second].stu[j];
            if (iq1 >= k_iq)
            {
                ans += cls[number[1]].sum;
                break;
            }
            else if (iq1 + iq2 > k_iq)
                ans++;
        }
    }
}

void dfs(int pos, int num)
{
    if (num == 2)
    {
        solve();
    }
    for (int k = pos; k <= n; k++)
    {
        number[num] = k;
        dfs(k + 1, num + 1);
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &sum_cls, &k_iq);
        for (int i = 1; i <= sum_cls; i++)
        {
            scanf("%d", &cls[i].sum);
            for (int j = 1; j <= cls[i].sum; j++)
            {
                int t_stu;
                scanf("%d", &t_stu);
                cls[i].stu.push_back(t_stu);
            }
        }
        n = sum_cls;
        ans = 0;
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
