#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1111;
int M, N;
char pic[maxn][maxn];
int vst[maxn][maxn][4];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct point
{
    int x, y, cnt, pdir;
    point()
    {
        x = y = cnt = 0, pdir = -1;
    }
};
point S, T;
bool check(point P)
{
    if (P.x > 0 && P.x <= M && P.y > 0 && P.y <= N && pic[P.x][P.y] != '*' && P.cnt <= 2)
        return true;
    return false;
}
bool bfs()
{
    memset(vst, 0x3f, sizeof(vst));
    point now, tmp;
    now.x = S.x, now.y = S.y, now.cnt = 0, now.pdir = -1;
    queue<point> q;
    q.push(now);
    for (int i = 0; i < 4; i++)
        vst[S.x][S.y][i] = 0;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (now.x == T.x && now.y == T.y)
            return true;
        for (int i = 0; i < 4; i++)
        {
            tmp.x = now.x + dir[i][0];
            tmp.y = now.y + dir[i][1];
            tmp.pdir = i;
            if (now.pdir == -1)
                tmp.cnt = 0;
            else if (tmp.pdir != now.pdir)
                tmp.cnt = now.cnt + 1;
            else if (tmp.pdir == now.pdir)
                tmp.cnt = now.cnt;
            //判断有无更优的路径
            if (vst[tmp.x][tmp.y][i] <= tmp.cnt)
                continue;
            if (check(tmp))
            {
                q.push(tmp);
                vst[tmp.x][tmp.y][i] = tmp.cnt;
            }
        }
    }
    return false;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &M, &N))
    {
        getchar();
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%c", &pic[i][j]);
                if (pic[i][j] == 'S')
                    S.x = i, S.y = j;
                else if (pic[i][j] == 'T')
                    T.x = i, T.y = j;
            }
            getchar();
        }
        bool ans = bfs();
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}