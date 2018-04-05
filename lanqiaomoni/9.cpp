#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1111;
char pic[maxn][maxn];
bool vst[maxn][maxn];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int N;
//点的结构体
struct point
{
    int x, y;
    point()
    {
        x = y = 0;
    }
};
// 检测点是否超出边界
bool check(point p)
{
    if (p.x >= 0 && p.x < N && p.y >= 0 && p.y < N && !vst[p.x][p.y] && pic[p.x][p.y] == '#')
        return true;
    return false;
}
// 广度搜索，对每一个#的联通块设置的vst[x][y]为true
void bfs(int x, int y)
{
    memset(vst, false, sizeof(vst));
    queue<point> q;
    point now, tmp;
    now.x = x, now.y = y;
    q.push(now);
    vst[x][y] = true;
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
                q.push(tmp);
                vst[tmp.x][tmp.y] = true;
            }
        }
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d", &N))
    {
        for (int i = 0; i < N; i++)
            scanf("%s", &pic[i]);
        // 预处理输入的数组，将临近.的#替换为*
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (pic[i][j] == '.')
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + dir[k][0], nj = j + dir[k][1];
                        if (ni < 0 || ni >= N || nj < 0 || nj >= N)
                            continue;
                        if (pic[ni][nj] == '#')
                            pic[ni][nj] = '*';
                    }
                }
        //广度搜索统计#联通块个数
        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!vst[i][j] && pic[i][j] == '#')
                {
                    bfs(i, j);
                    ans++;
                }
        printf("%d\n", ans);
    }
    return 0;
}