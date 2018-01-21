#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
int n, m, num[111];
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m) && n != 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (m <= num[i] && flag)
            {
                flag = false;
                printf("%d ", m);
            }
            printf("%d%c", num[i], (i == (n - 1)) && (m <= num[n - 1]) ? '\n' : ' ');
            if (i == n - 1 && m > num[n - 1])
                printf("%d\n", m);
        }
    }
    return 0;
}
