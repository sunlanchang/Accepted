#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>
#include <queue>

using namespace std;

#define ONLINE_JUDGE
int col, line, sx, sy, cnt;
int m[50][50];
bool visit[50][50];
int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

struct states
{
    int x;
    int y;
    states(int x, int y) : x(x), y(y) {}
};

void init(int line, int col)
{
    for (int i = 1; i <= line; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            m[i][j] = 0;
            visit[i][j] = false;
        }
    }
    cnt = 0;
}

void bfs(int sx, int sy)
{
    queue<states> Q;
    Q.push(states(sx, sy));
    visit[sx][sy] = true;
    while (!Q.empty())
    {
        cnt++;
        states t = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = t.x + x[dir];
            int ny = t.y + y[dir];
            if (nx >= 1 && nx <= line && ny >= 1 && ny <= col && !visit[nx][ny] && m[nx][ny] != 0)
            {
                visit[nx][ny] = true;
                Q.push(states(nx, ny));
            }
        }
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    long _begin_time = clock();
#endif

    while (~scanf("%d%d", &col, &line) && col && line)
    {
        init(line, col);
        for (int i = 1; i <= line; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '#')
                    m[i][j] = 0;
                else if (ch == '.')
                    m[i][j] = 1;
                else if (ch == '@')
                {
                    sx = i;
                    sy = j;
                    m[i][j] = 2;
                }
            }
        }
        bfs(sx, sy);
        printf("%d\n", cnt);
    }

#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %ld ms\n", _end_time - _begin_time);
#endif
    return 0;
}
