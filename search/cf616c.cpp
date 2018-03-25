#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1111;
int vst[maxn][maxn];
char pic[maxn][maxn];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int p[maxn * maxn];
int m, n;
struct point
{
    int x, y, order;
    point()
    {
        x = y = order = 0;
    }
};
bool check(point pt)
{
    if (pt.x >= 0 && pt.x < m && pt.y >= 0 && pt.y < n && vst[pt.x][pt.y] == 0 && pic[pt.x][pt.y] == '.')
        return true;
    return false;
}
void bfs(int x, int y, int order)
{
    queue<point> q;
    point now, tmp;
    now.x = x, now.y = y;
    int cnt = 0;
    q.push(now);
    vst[x][y] = order;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            tmp.x = now.x + dir[i][0];
            tmp.y = now.y + dir[i][1];
            if (check(tmp))
            {
                cnt++;
                q.push(tmp);
                vst[tmp.x][tmp.y] = order;
            }
        }
    }
    p[order] = cnt + 1;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    memset(p, 0, sizeof(p));
    while (~scanf("%d%d", &m, &n))
    {
        memset(vst, false, sizeof(vst));
        int ans = 1, order = 1;
        for (int i = 0; i < m; i++)
            scanf("%s", pic[i]);
        // 预处理.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pic[i][j] == '.' && vst[i][j] == 0)
                {
                    bfs(i, j, order);
                    order++;
                }
            }
        }
        // 上下左右方向的块加起来
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pic[i][j] == '*')
                {
                    int ans = 0;
                    map<int, int> map_;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dir[k][0], y = j + dir[k][1];
                        if (x >= 0 && x < m && y >= 0 && y < n && pic[x][y] == '.')
                        {
                            if (map_.count(vst[x][y]) == 0)
                            {
                                map_[vst[x][y]] = 1;
                                ans += p[vst[x][y]];
                            }
                        }
                    }
                    printf("%d", (ans + 1) % 10);
                }
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    return 0;
}