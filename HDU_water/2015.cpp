#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int num, len;
int n[111];

int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &num, &len))
    {
        memset(n, 0, sizeof(n));
        int num2 = num, cnt = len / num;
        for (int i = 1; i <= num; i++)
            n[i] = n[i - 1] + 2;
        int s = 0;
        for (int i = 1; i <= num; i++)
        {
            s += n[i];
            if (i % len == 0)
            {
                s /= len;
                printf("%d%c", s, i == num ? '\n' : ' ');
                s = 0;
            }
            else if (i == num)
            {
                s /= (num % len);
                printf("%d\n", s);
            }
        }
    }
    return 0;
}
