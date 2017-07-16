#include <functional>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

bool exist(vector<int> v, int e)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == e)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int num;
    while (scanf("%d", &num) != EOF)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        long long int ans = 0;
        for (int i = 0; i < num; i++)
        {
            int len;
            scanf("%d", &len);
            q.push(len);
        }
        while (q.size() != 1 && num != 0)
        {
            int tmp_len1 = q.top();
            q.pop();
            int tmp_len2 = q.top();
            q.pop();
            int sum_len = tmp_len1 + tmp_len2;
            ans += sum_len;
            q.push(sum_len);
        }
        cout << ans << "\n";
    }
    return 0;
}