#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int N;
    while (~scanf("%d", &N))
    {
        int a[10];
        int b[10];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < N; i++)
        {
            int index;
            scanf("%d", &index);
            a[index]++;
        }
        for (int i = 0; i < N; i++)
        {
            int index;
            scanf("%d", &index);
            b[index]++;
        }
        int res = 0;
        bool no_ans = false;
        for (int i = 1; i <= 5; i++)
        {
            if ((a[i] + b[i]) % 2 != 0)
            {
                no_ans = true;
                break;
            }
            res += abs(a[i] - b[i]) / 2;
        }
        if (no_ans)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << res / 2 << "\n";
        }
    }
    return 0;
}