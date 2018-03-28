#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e3 + 10;
bool vst[maxn][maxn];
int pic[maxn][maxn];
int M, N, SX, SY, ANS;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool check(int x, int y)
{
    //注意状态检测先检测边界！如果先检测vst会有数组越界的危险
    if (x > 0 && x <= M && y > 0 && y <= N && !vst[x][y] && pic[x][y] <= pic[SX][SY])
        return true;
    return false;
}
void DFS(int sx, int sy)
{
    vst[sx][sy] = true;
    ANS++;
    // 不同于BFS这里没有目标状态的检测
    for (int i = 0; i < 4; i++)
    {
        //构造下一次状态
        int nx = sx + dir[i][0], ny = sy + dir[i][1];
        //状态检测
        if (check(nx, ny))
        {
            //直接递归，不同于BFS，不需要改变状态数组vst
            DFS(nx, ny);
        }
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d%d%d", &M, &N, &SX, &SY))
    {
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &pic[i][j]);
        ANS = 0;
        memset(vst, false, sizeof(vst));
        DFS(SX, SY);
        printf("%d\n", ANS);
    }
    return 0;
}