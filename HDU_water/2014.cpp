#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

double num[111];

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n))
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
            scanf("%lf", &num[i]);
        sort(num, num + n);
        for (int i = 1; i < n - 1; i++)
            sum += num[i];
        printf("%.2f\n", sum / (n - 2));
    }
    return 0;
}
