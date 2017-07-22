#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 1000000000;
const int maxn = 110000;
int N, C;
int x[maxn];

bool Check(int mid)
{
    int num = 1, cur = 0, last = 0, i = 0;
    while (i < N)
    {
        if (x[cur] - x[last] >= mid)
        {
            num++;
            last = cur;
        }
        i++;
        cur = i;
    }
    if (num >= C)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    while (~scanf("%d%d", &N, &C))
    {
        memset(x, 0, sizeof(x));
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &x[i]);
        }
        sort(x, x + N);
        int l = 0, r = INF;
        for (int t = 0; t < 100; t++)
        {
            int mid = l + (r - l) / 2;
            if (Check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        cout << l << "\n";
    }
    return 0;
}