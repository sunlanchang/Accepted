#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
int num[20];

int main()
{
    // freopen("in.txt", "r", stdin);
    int T;
    int cnt = 1;
    while (~scanf("%d", &T))
    {
        for (int i = 0; i < T; i++)
            scanf("%d", &num[i]);
        long long product = 1, ans = -INF;
        for (int i = 0; i < T; i++)
        {
            product = 1;
            for (int j = i; j < T; j++)
            {
                product *= num[j];
                ans = max(product, ans);
            }
        }
        if (ans > 0)
            printf("Case #%d: The maximum product is %lld.\n\n", cnt++, ans);
        else
            printf("Case #%d: The maximum product is 0.\n\n", cnt++);
    }
    return 0;
}
