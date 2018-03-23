#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 1000 + 10

using namespace std;

int final_;
int vis[maxn][maxn];
int map[maxn][maxn];
int s[maxn][maxn];
int m, n;

int move_[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct point
{
    int x, y;
};

bool check(point a)
{
    if (a.x >= 1 && a.x <= n && a.y >= 1 && a.y <= m && vis[a.x][a.y] == 0 && map[a.x][a.y] <= final_)
        return true;
    return false;
}

int bfs(int x, int y)
{
    queue<point> que;
    point now, next;
    int count = 1;
    now.x = x;
    now.y = y;
    que.push(now);
    vis[x][y] = 1;
    s[x][y] = 1;

    while (!que.empty())
    {
        now = que.front();
        que.pop();
        if (s[now.x][now.y] == 1)
        {

            for (int i = 0; i < 4; i++)
            {
                next.x = now.x + move_[i][0];
                next.y = now.y + move_[i][1];
                if (check(next))
                {
                    que.push(next);
                    vis[next.x][next.y] = 1;
                    count++;
                    s[next.x][next.y] = 1;
                }
            }
        }
    }
    return count;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int p1, p2;
    while (scanf("%d%d%d%d", &n, &m, &p1, &p2) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        memset(s, 0, sizeof(s));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &map[i][j]);
        final_ = map[p1][p2];
        printf("%d\n", bfs(p1, p2));
    }
}