#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 1111
int T, n, m[1111];
ll k, v[1111][111], a[111111];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lld", &n, &k);
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &m[i]);
            for (int j = 0; j < m[i]; j++)
                scanf("%lld", &v[i][j]), a[res++] = v[i][j];
            sort(v[i], v[i] + m[i]);
        }
        sort(a, a + res);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < m[i]; j++)
            {
                int pos;
                //所有数中大于k-v[i][j]的
                pos = upper_bound(a, a + res, k - v[i][j]) - a;
                ans += (res - pos);
                //在第i个集合中大于k-v[i][j]的要减掉，因为要从不同的集合取数
                pos = upper_bound(v[i], v[i] + m[i], k - v[i][j]) - v[i];
                ans -= (m[i] - pos);
            }
        printf("%lld\n", ans / 2);
    }
    return 0;
}