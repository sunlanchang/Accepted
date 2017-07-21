#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

#define ONLINE_JUDGE

const int maxn = 11000;
int N, M, T, dx, dy;
char m[maxn][10];
bool visit[maxn][10];
bool ANS;
int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

void init()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            m[i][j] = '.';
            visit[i][j] = false;
        }
    }
    ANS = false;
}

void dfs(int i, int j, int step)
{
    int temp1 = abs(i - dx) - abs(j - dy);
    int temp2 = T - step;
    if (abs(temp1 - temp2) % 2 == 1 || temp2 < 0)
    {
        return;
    }
    if (m[i][j] == 'D' && step == T)
    {
        ANS = true;
        return;
    }
    if (ANS)
    {
        return;
    }
    for (int ii = 0; ii < 4; ii++)
    {
        int nx = i + x[ii];
        int ny = j + y[ii];
        if (!visit[nx][ny] && nx >= 1 && nx <= N && ny >= 1 && ny <= M && m[nx][ny] != 'X')
        {
            visit[nx][ny] = true;
            dfs(nx, ny, step + 1);
            visit[nx][ny] = false;
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
    while (~scanf("%d%d%d", &N, &M, &T) && (N || M || T))
    {
        init();
        int xx, yy, num_x = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                // scanf("%c", &m[i][j]);
                cin >> m[i][j];
                if (m[i][j] == 'S')
                {
                    xx = i;
                    yy = j;
                }
                else if (m[i][j] == 'D')
                {
                    dx = i;
                    dy = j;
                }
                else if (m[i][j] == 'X')
                {
                    num_x++;
                }
            }
        }
        if (N * M - num_x < T + 1)
        {
            printf("NO\n");
            continue;
        }
        visit[xx][yy] = true;
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
