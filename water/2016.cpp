#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

const int INF = 0x3f3f3f3f;
int num[111];

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n) && n)
    {
        int index = -1, m = INF;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            if (num[i] < m)
            {
                index = i;
                m = num[i];
            }
        }
        int t = num[index];
        num[index] = num[0];
        num[0] = t;
        for (int i = 0; i < n; i++)
            printf("%d%c", num[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
