#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    ll l, r, x, y, k;
    while (~scanf("%lld%lld%lld%lld%lld", &l, &r, &x, &y, &k))
    {
        bool flag = true;
        for (ll i = x; i <= y; i++)
        {
            ll t = k * i;
            if (t >= l && t <= r)
            {
                printf("YES\n");
                flag = false;
                break;
            }
        }
        if (flag)
            printf("NO\n");
    }
    return 0;
}
