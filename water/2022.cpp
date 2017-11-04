#include <cstdio>
#include <algorithm>
using namespace std;
int m, n, g;
int main()
{
    while (~scanf("%d%d", &m, &n) && (m || n))
    {
        int x = 1, y = 1, res, maxg = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &g);
                if (abs(g) > maxg)
                {
                    x = i, y = j, res = g;
                    maxg = max(abs(g), maxg);
                }
            }
        printf("%d %d %d\n", x, y, res);
    }
    return 0;
}
