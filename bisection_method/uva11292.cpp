#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 20010;
int dr[maxn], kn[maxn];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m;
    while (~scanf("%d%d", &n, &m) && (n || m))
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &dr[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &kn[i]);
        sort(dr, dr + n);
        sort(kn, kn + m);
        int ans = 0, start = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = start; j < m; j++)
            {
                if (dr[i] <= kn[j])
                {
                    cnt++;
                    ans += kn[j];
                    start = j + 1;
                    break;
                }
            }
        }
        if (cnt == n)
            printf("%d\n", ans);
        else
            printf("Loowater is doomed!\n");
    }
    return 0;
}
