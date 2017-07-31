#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const long long int INF = 0x3f3f3f3f;
const int maxn = 1111;
int n, res, m[maxn];
long long int k, a[111111], v[maxn][maxn];

int main()
{
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        res = 0;
        scanf("%d%lld", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &m[i]);
            for (int j = 0; j < m[i]; j++)
            {
                scanf("%lld", &v[i][j]);
                a[res++] = v[i][j];
            }
            sort(v[i], v[i] + m[i]);
        }
        sort(a, a + res);
        long long ans = 0, pos = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m[i]; j++)
            {
                pos = upper_bound(a, a + res, k - v[i][j]) - a;
                ans += (res - pos);
                pos = upper_bound(v[i], v[i] + m[i], k - v[i][j]) - v[i];
                ans -= (m[i] - pos);
            }
        printf("%lld\n", ans / 2);
    }
    return 0;
}
