#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int col, row;
char m[111][111];
int visit[111][111];

void bfs(int px, int py)
{
    queue<pair<int, int>> q;
    pair<int, int> start = make_pair(px, py);
    visit[px][py] = 1;
    q.push(start);
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int dx2 = pos.first + dx[i], dy2 = pos.second + dy[i];
            if (dx2 >= 0 && dx2 < row && dy2 >= 0 && dy2 < col && !visit[dx2][dy2] && m[dx2][dy2] == '@')
            {
                visit[dx2][dy2] = 1;
                pair<int, int> tmp = make_pair(dx2, dy2);
                q.push(tmp);
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &row, &col) && col && row)
    {
        int ans = 0;
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < row; i++)
            scanf("%s", &m[i]);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (!visit[i][j] && m[i][j] == '@')
                {
                    ans++;
                    bfs(i, j);
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
