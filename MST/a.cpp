#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct edge
{
    int u, v, w;
};

int pre[110], M, N;
edge edges[50010];

void init(int N, int M)
{
    for (int i = 1; i <= M; i++)
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
        pre[j] = i;
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int main()
{

    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &N, &M) && N)
    {
        init(N, M);
        for (int i = 1; i <= N; i++)
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        sort(edges + 1, edges + 1 + N, cmp);
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            if (find(edges[i].u) != find(edges[i].v))
            {
                unite(edges[i].u, edges[i].v);
                ans += edges[i].w;
            }
        }
        int flag = false;
        for (int i = 2; i <= M; i++)
        {
            if (find(1) != find(i))
            {
                flag = true;
                break;
            }
        }
        if (flag)
            printf("?\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
