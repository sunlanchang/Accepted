#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>
#include <utility>

using namespace std;

#define ONLINE_JUDGE
char m[400][400];
int visit[400][400];
int COUNT, N, M;
int xx[4] = {0, 0, -1, 1};
int yy[4] = {-1, 1, 0, 0};

void init()
{
    memset(m, 0, sizeof(m));
    memset(visit, 0, sizeof(visit));
}

void dfs(int x, int y, int count)
{
    if (m[x][y] == 'r')
    {
        COUNT = min(COUNT, count);
        return;
    }
    if (count >= COUNT)
        return;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (!visit[nx][ny] && nx >= 1 && nx <= N && ny >= 1 && ny <= M && m[nx][ny] != '#')
        {
            visit[nx][ny] = 1;
            if (m[x][y] == 'x')
                dfs(nx, ny, count + 2);
            else
                dfs(nx, ny, count + 1);
            visit[nx][ny] = 0;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    long _begin_time = clock();
#endif
    pair<int, int> start;
    while (~scanf("%d%d", &N, &M))
    {
        init();
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cin >> m[i][j];
                if (m[i][j] == 'a')
                    start = make_pair(i, j);
            }
        }
        COUNT = 0x3f3f3f3f;
        visit[start.first][start.second] = 1;
        dfs(start.first, start.second, 0);
        if (COUNT < 0x3f3f3f3f)
            printf("%d\n", COUNT);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %.2f ms\n", double(_end_time - _begin_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}
