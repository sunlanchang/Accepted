#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

double cables[10010];

bool check(double m, int N, int K)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += cables[i] / m;
    }
    if (ans >= K)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int N, K;
    while (~scanf("%d%d", &N, &K))
    {
        double sum = 0;
        memset(cables, 0, sizeof(cables));
        for (int i = 0; i < N; i++)
        {
            //输入double必须用%lf
            scanf("%f", &cables[i]);
            sum += cables[i];
        }
        double l = 0, r = sum;
        while (r - l > 1e-5)
        {
            double m = l + (r - l) / 2.0;
            if (check(m, N, K))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        //%lf g++WA， %f g++/c++都能A
        printf("%.2f\n", floor(r * 100) / 100.0);
    }
    return 0;
}