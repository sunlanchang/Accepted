#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m, v, i, j, d[50005], a, b;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &m, &v);
        memset(d, -100, sizeof(d));
        d[0] = 0;
        for (i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            for (j = a; j <= v; j++)
            {
                d[j] = max(d[j - a] + b, d[j]);
            }
            for (int i = 0; i < 10; i++)
            {
                cout << d[i] << " ";
            }
            cout << "\n";
        }
        if (d[v] < 0)
            printf("NO\n");
        else
            printf("%d\n", d[v]);
    }
    return 0;
}