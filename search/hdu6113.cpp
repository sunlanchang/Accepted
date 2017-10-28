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
int n, m;
void dfs(int i, int j)
{
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
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) == 2)
    {
        // cout << "test" << endl;
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);
        int cnt1 = 0, cnt0 = 0;
        memset(mark, 0, sizeof(mark));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!mark[i][j])
                {
                    if (s[i][j] == '1')
                    {
                        cnt1++;
                    }
                    dfs(i, j);
                }
            }
        }
        cout << "cnt1: " << cnt1 << endl;
    }
    return 0;
}
