#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

// #define ONLINE_JUDGE

const int maxn = 11000;
int N, M, T, dx, dy;
char m[maxn][10];
bool visit[maxn][10];
bool ANS;
int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            m[i][j] = '.';
            visit[i][j] = false;
        }
    }
    ANS = false;
}

void dfs(int i, int j, int step)
{
    int temp = T - step - abs(i - j) - abs(dx - dy);
    if (temp % 2 == 1)
    {
        return;
    }
    if (m[i][j] == 'D' && step == T)
    {
        ANS = true;
        return;
    }
    visit[i][j] = true;
    for (int ii = 0; ii < 4; ii++)
    {
        if (step > T || i < 0 || i > N - 1 || j < 0 || j > M - 1 || m[i][j] == 'X')
        {
            continue;
        }
        if (visit[i + x[ii]][j + y[ii]] == false)
        {
            visit[i + x[ii]][j + y[ii]] = true;
            dfs(i + x[ii], j + y[ii], step + 1);
            visit[i + x[ii]][j + y[ii]] = false;
        }
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long _begin_time = clock();
#endif
    while (scanf("%d%d%d", &N, &M, &T) && (N || M || T))
    {
        init();
        int xx, yy;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                // scanf("%c", &m[i][j]);
                cin >> m[i][j];
                if (m[i][j] == 'S')
                {
                    xx = i;
                    yy = j;
                }
                if (m[i][j] == 'D')
                {
                    dx = i;
                    dy = j;
                }
            }
        }
        dfs(xx, yy, 0);
        if (ANS)
            printf("YES\n");
        else
            printf("NO\n");
    }
#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %ld ms\n", _end_time - _begin_time);
#endif
    return 0;
}
