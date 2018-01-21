#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const long N = 100000 + 5;
int m, n;
int set[N + N];
int set_find(int d)
{
    if (set[d] < 0)
        return d;
    return set[d] = set_find(set[d]);
}
void unite(int p, int q)
{
    p = set_find(p);
    q = set_find(q);
    if (p != q)
        set[p] = q;
}
int main()
{
    int T, i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(set, -1, sizeof(set)); //初始化时各成一派
        for (i = 0; i < m; ++i)
        {
            int a, b;
            char s[5];
            scanf("%s%d%d", s, &a, &b);
            if (s[0] == 'A') //询问
            {
                if (set_find(a) != set_find(b) && set_find(a) != set_find(b + n))
                    printf("%s\n", "Not sure yet.");
                else if (set_find(a) == set_find(b))
                    printf("%s\n", "In the same gang.");
                else
                    printf("%s\n", "In different gangs.");
            }
            else //合并
            {
                unite(a, b + n);
                unite(b, a + n);
            }
        }
    }
    return 0;
}
