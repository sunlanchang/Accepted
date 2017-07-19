#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[11000];
int b[11000];
int c[11000];
int n;

double f(double x)
{
    double ans = a[0] * x * x + b[0] * x + c[0];
    for (int i = 0; i < n; i++)
    {
        double tmp = a[i] * x * x + b[i] * x + c[i];
        ans = max(ans, tmp);
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(a));
        memset(c, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
        double l = 0, r = 1000;
        for (int t = 0; t < 100; t++)
        {
            double mid1 = l + (r - l) / 2;
            double mid2 = mid1 + (r - mid1) / 2;
            double f1 = f(mid1), f2 = f(mid2);
            if (f1 >= f2)
            {
                l = mid1;
            }
            else
            {
                r = mid2;
            }
        }
        double ans = f(l);
        printf("%.4f\n", ans);
    }
    return 0;
}