#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

double cables[10010];

;

int main()
{
    int N, K;
    while (~scanf("%d%d", &N, &K))
    {
        double sum = 0;
        memset(cables, 0, sizeof(cables));
        for (int i = 0; i < N; i++)
        {
            scanf("%lf", &cables[i]);
            sum += cables[i];
        }
        int l = 0, r = sum / N + 1, m = -1;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (check())
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        int ans = r;
    }
    return 0;
}