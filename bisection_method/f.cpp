#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double len, t, c;
    while (scanf("%lf%lf%lf", &len, &t, &c) && len >= 0 && t >= 0 && c >= 0)
    {
        double l = 0, r = len;
        double len2 = (1.0 + t * c) * len;
        for (int cnt = 0; cnt < 100; cnt++)
        {
            double h = 0.5 * (l + r);
            double R = (h * h + l * l / 4) / (2.0 * h);
            double a = asin(l / (2.0 * R));
        }
    }
    return 0;
}