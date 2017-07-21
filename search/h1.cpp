#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>
#include <utility>

using namespace std;

#define ONLINE_JUDGE

int N, M;
char m[500][500];
pair<int, int> pre[500][500];
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};

void init(int N, int M)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            m[i][j] = '0';
            pre[i][j] = make_pair(i, j);
        }
    }
}

pair<int, int> find(pair<int, int> x)
{
    if (pre[x.first][x.second] == x)
        return x;
    return pre[x.first][x.second] = find(pre[x.first][x.second]);
}

void Unite(pair<int, int> i, pair<int, int> j)
{
    pair<int, int> iroot = find(i);
    pair<int, int> jroot = find(j);
    if (iroot != jroot)
    {
        pre[jroot.first][jroot.second] = iroot;
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    long _begin_time = clock();
#endif
    while (~scanf("%d%d", &M, &N) && N && M)
    {
        init(N, M);
        pair<int, int> pos;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cin >> m[i][j];
                if (m[i][j] == '@')
                {
                    pos = make_pair(i, j);
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + x[k];
                    int ny = j + y[k];
                    if (m[i][j] != '#' && m[nx][ny] != '#' && nx >= 1 && nx <= N && ny >= 1 && ny <= M)
                    {
                        pair<int, int> crt = make_pair(i, j);
                        pair<int, int> next = make_pair(nx, ny);
                        Unite(crt, next);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (find(pos) == find(make_pair(i, j)))
                {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %ld ms\n", _end_time - _begin_time);
#endif
    return 0;
}
