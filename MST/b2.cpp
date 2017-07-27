#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Edge
{
    int u, v;
    double w;
};

const int INF = 0x3f3f3f3f;
Edge edges[11000];
int x[110], y[110];
int pre[150];
int num;

void init()
{
    for (int i = 1; i <= num; i++)
        pre[i] = i;
}

int find(int x)
{
    if (x == pre[x])
        return x;
    return pre[x] = find(pre[x]);
}

void unite(int i, int j)
{
    if (find(i) != find(j))
        pre[find(j)] = find(i);
}

bool cmp(Edge a, Edge b)
{
    if (a.w != b.w)
        return a.w < b.w;
    if (a.u != b.u)
        return a.u < b.u;
    return a.v < b.v;
}

double kruskal()
{
    double ans = 0;
    sort(edges + 1, edges + 1 + num * num, cmp);
    for (int i = 1; i <= num * num; i++)
    {
        if (edges[i].w != INF && (find(edges[i].u) != find(edges[i].v)))
        {
            unite(edges[i].u, edges[i].v);
            ans += edges[i].w;
        }
    }
    for (int i = 2; i <= num; i++)
        if (find(i) != find(1))
            return -1;
    return ans * 100;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &num);
        init();
        for (int i = 1; i <= num; i++)
            scanf("%d%d", &x[i], &y[i]);
        int t_cnt = 1;
        for (int i = 1; i <= num; i++)
            for (int j = 1; j <= num; j++)
            {
                edges[t_cnt].u = i, edges[t_cnt].v = j;
                double tx = x[i] - x[j], ty = y[i] - y[j];
                double dis = sqrt(tx * tx + ty * ty);
                if (dis > 1000 || dis < 10)
                    edges[t_cnt].w = INF;
                else
                    edges[t_cnt].w = dis;
                t_cnt++;
            }
        double ans = kruskal();
        if (ans == -1)
            printf("oh!\n");
        else
            printf("%.1f\n", ans);
    }
    return 0;
}
