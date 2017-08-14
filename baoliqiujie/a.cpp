#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int a[111];

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int t = min(a[i], 8);
            a[i + 1] += (a[i] - t);
            k -= t;
            if (k <= 0)
            {
                ans = i;
                break;
            }
        }
        if (ans == -1)
            printf("-1\n");
        else
            printf("%d\n", ans + 1);
    }
    return 0;
}
