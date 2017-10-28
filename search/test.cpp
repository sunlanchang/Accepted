#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <ctime>
using namespace std;
#define maxn 111
char s[maxn][maxn];
int n, m, mark[maxn][maxn], L, R, U, D;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void dfs(int x, int y)
{
    if (s[x][y] == '0')
        U = min(U, x), D = max(D, x), L = min(L, y), R = max(R, y);
    mark[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || mark[xx][yy] || s[xx][yy] != s[x][y])
            continue;
        dfs(xx, yy);
    }
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);
        memset(mark, 0, sizeof(mark));
        int num1 = 0; //1连通块数量
        int cnt0 = 0; //被1包围的0连通块数量
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!mark[i][j])
                {
                    if (s[i][j] == '1')
                        num1++;
                    L = m, R = 1, U = n, D = 1;
                    dfs(i, j);
                    if (s[i][j] == '0' && L > 1 && R < m && U > 1 && D < n)
                        cnt0++;
                }
        if (num1 == 1 && cnt0 == 1)
            printf("0\n");
        else if (num1 == 1 && cnt0 == 0)
            printf("1\n");
        else
            printf("-1\n");
    }
    return 0;
}