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
int main()
{
    double L, n, C;
    while (~scanf("%lf%lf%lf", &L, &n, &C), L >= 0 && n >= 0 && C >= 0)
    {
        double LL = (1.0 + n * C) * L;
        double l = 0, r = 0.5 * L, h;
        int t = 100;
        while (t--)
        {
            h = 0.5 * (l + r);
            double R = (L * L / 4.0 + h * h) / (2.0 * h);
            double a = asin(L / (2.0 * R));
            if (R * a >= 0.5 * LL)
                r = h;
            else
                l = h;
        }
        printf("%.3f\n", h);
    }
    return 0;
}