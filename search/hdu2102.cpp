#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 111;
bool vst[maxn][maxn][maxn];
char pic[maxn][maxn][maxn];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int M, N, T;
struct point
{
    int x, y, z, cnt;
    point()
    {
        x = y = z = cnt = 0;
    }
};
point P;
bool check(point tmp)
{
    int x = tmp.x, y = tmp.y, z = tmp.z, cnt = tmp.cnt;
    //时间问题
    if (!vst[z][x][y] && pic[z][x][y] != '*' && cnt <= T && x >= 0 && x < M && y >= 0 && y < N)
    {
        return true;
    }
    return false;
}
bool bfs()
{
    memset(vst, 0, sizeof(vst));
    point now, tmp;
    now.x = 0, now.y = 0, now.z = 0, now.cnt = 0;
    queue<point> q;
    q.push(now);
    vst[0][0][0] = true;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (now.x == P.x && now.y == P.y && now.z == P.z && now.cnt <= P.cnt)
        {
            return true;
        }
        for (int i = 0; i < 4; i++)
        {
            tmp.x = now.x + dir[i][0];
            tmp.y = now.y + dir[i][1];
            tmp.z = now.z;
            if (pic[tmp.z][tmp.x][tmp.y] == '#')
            {
                tmp.z = abs(tmp.z - 1);
            }
            if (check(tmp))
            {
                tmp.cnt = now.cnt + 1;
                q.push(tmp);
                vst[tmp.z][tmp.x][tmp.y] = true;
            }
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int C;
    scanf("%d", &C);
    while (C--)
    {
        scanf("%d%d%d", &M, &N, &T);
        P.cnt = T;
        for (int z = 0; z < 2; z++)
        {
            for (int i = 0; i < M; i++)
            {
                scanf("%s", &pic[z][i]);
                for (int j = 0; j < N; j++)
                {
                    if (pic[z][i][j] == 'P')
                    {
                        P.z = z, P.x = i, P.y = j;
                        // cout << P.x << endl;
                        // cout << P.y << endl;
                        // cout << P.z << endl;
                    }
                }
            }
        }

        // for (int z = 0; z < 2; z++)
        // {
        //     for (int i = 0; i < M; i++)
        //     {
        //         for (int j = 0; j < N; j++)
        //         {
        //             cout << pic[z][i][j];
        //         }
        //         cout << endl;
        //     }
        //     cout << endl
        //          << endl;
        // }

        bool ans = bfs();
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}