#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[11000];
int b[11000];
int c[11000];

int main()
{
    int T;
    while (T--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(a));
        memset(c, 0, sizeof(a));
        int n;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
    }
    return 0;
}