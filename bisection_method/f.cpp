#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double L, t, c;
    while (scanf("%lf%lf%lf", &L, &t, &c) && L >= 0 && t >= 0 && c >= 0)
    {
        double left = 0, right = 0.5 * L, h;
        double LL = (1.0 + t * c) * L;
        for (int cnt = 0; cnt < 100; cnt++)
        {
            h = 0.5 * (left + right);
            double R = (h * h + L * L / 4.0) / (2.0 * h);
            double a = asin(L / (2.0 * R));
            if (R * a >= LL / 2.0)
            {
                right = h;
            }
            else
            {
                left = h;
            }
        }
        printf("%.3f\n", h);
    }
    return 0;
}