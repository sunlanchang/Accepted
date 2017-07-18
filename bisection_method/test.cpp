#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 10010;

int x[MAX];
int y[MAX];
int z[MAX];

int main()
{
    int N;
    while (~scanf("%d", &N))
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(x));
        memset(z, 0, sizeof(x));
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
        }
        sort(x, x + N);
        sort(y, y + N);
        for (int i = 0; i < N; i++)
        {
            z[i] = x[i] - i;
        }
        sort(z, z + N);
        int ans_x = z[N / 2], ans_y = y[N / 2], res = 0;
        for (int i = 0; i < N; i++)
        {
            res += abs(z[i] - ans_x);
            res += abs(y[i] - ans_y);
        }
        printf("%d", res);
    }
    return 0;
}