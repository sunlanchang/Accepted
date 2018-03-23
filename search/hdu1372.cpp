#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int sx, sy, ex, ey;
int vst[10][10], pic[10][10];
int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
struct point
{
    int x, y, cnt;
};
bool check(point p)
{
    if (!vst[p.x][p.y] && p.x > 0 && p.x < 9 && p.y > 0 && p.y < 9)
        return true;
    return false;
}
int bfs()
{
    memset(vst, 0, sizeof(vst));
    queue<point> q;
    point now, next;
    now.x = sx, now.y = sy, now.cnt = 0;
    q.push(now);
    vst[now.x][now.y] = 1;
    while (!q.empty())
    {
        next = q.front();
        q.pop();
        if (next.x == ex && next.y == ey)
            return next.cnt;
        for (int i = 0; i < 8; i++)
        {
            point tmp;
            tmp.x = dir[i][0] + next.x;
            tmp.y = dir[i][1] + next.y;
            if (check(tmp))
            {
                tmp.cnt = next.cnt + 1;
                q.push(tmp);
                vst[tmp.x][tmp.y] = 1;
            }
        }
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    char a[3], b[3];
    while (~scanf("%s %s", a, b))
    {
        sx = a[0] - 'a' + 1, sy = a[1] - '1' + 1;
        ex = b[0] - 'a' + 1, ey = b[1] - '1' + 1;
        int ans = bfs();
        printf("To get from %s to %s takes %d knight moves.\n", a, b, ans);
    }
    return 0;
}