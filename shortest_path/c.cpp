#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Edge
{
    int u, v, w;
};

const int INF = 0x3f3f3f3f;
const int maxn = 110;
Edge e[maxn * (maxn - 1) / 2];
int pre[maxn];
int N;

void init()
{
    for (int i = 1; i <= N; i++)
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

int kruskal(int cnt)
{
    sort(e + 1, e + 1 + cnt, cmp);
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (find(e[i].u) != find(e[i].v))
        {
            unite(e[i].u, e[i].v);
            ans += e[i].w;
        }
    }
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d", &N) && N)
    {
        init();
        int cnt = 1;
        for (int i = 1; i <= N * (N - 1) / 2; i++)
        {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (d == 0)
                e[cnt].u = a, e[cnt].v = b, e[cnt++].w = c;
            else
                unite(a, b);
        }
        int ans = kruskal(cnt - 1);
        printf("%d\n", ans);
    }
    return 0;
}
