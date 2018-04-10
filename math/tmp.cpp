#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
const int MAXN = 1000010;
long long a[MAXN], b[MAXN];
int main()
{
    int n;
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) == 1)
    {
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]); //Uva上要用lld
            sum += a[i];
        }
        long long A = sum / n;
        b[0] = 0;
        for (int i = 1; i < n; i++)
            b[i] = b[i - 1] + A - a[i + 1];
        cout << "b: ";
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
        sort(b, b + n);
        long long t = b[n / 2];
        cout << "t: " << t << endl;
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(t - b[i]);
        printf("%lld\n", ans); //Uva上要用lld
    }
    return 0;
}