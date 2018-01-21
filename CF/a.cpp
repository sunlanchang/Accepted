#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n, k, t;

int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d%d", &n, &k, &t))
    {
        int ans = 0;
        if (t <= k)
            ans = t;
        else if (t > k && t <= n)
            ans = k;
        else
            ans = k - (t - n);
        printf("%d\n", ans);
    }
    return 0;
}
