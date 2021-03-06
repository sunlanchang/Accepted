#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 111;
char s[maxn][maxn];
int mark[maxn][maxn];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, U, D, L, R;
void dfs(int i, int j)
{
    if (s[i][j] == '0')
        U = min(U, i), D = max(D, i), L = min(L, j), R = max(R, j);
    mark[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (mark[x][y] || x < 1 || x > n || y < 1 || y > m || s[x][y] != s[i][j])
            continue;
        dfs(x, y);
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);
        int cnt1 = 0; //1连通块数量
        int cnt0 = 0; //被1包围0联通快数量
        memset(mark, 0, sizeof(mark));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!mark[i][j])
                {
                    L = m, R = 1, U = n, D = 1;
                    dfs(i, j);
                    if (s[i][j] == '1')
                        cnt1++;
                    //LRUD分别代表0联通快的范围，若该范围与边界重合则没有被包围
                    if (s[i][j] == '0' && L > 1 && R < m && U > 1 && D < n)
                        cnt0++;
                }
        if (cnt1 == 1 && cnt0 == 0)
            printf("1\n");
        else if (cnt1 == 1 && cnt0 == 1)
            printf("0\n");
        else
            printf("-1\n");
    }
    return 0;
}
