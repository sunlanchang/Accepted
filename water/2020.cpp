#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
bool cmp(int a, int b)
{
    return abs(a) > abs(b);
}
int n, num[111];
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        sort(num, num + n, cmp);
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", num[i], i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
