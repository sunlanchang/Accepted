#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
//Kruskal

struct Point
{
    int x, y;
};
struct Edge
{
    int u, v;
    double w;
};

const int INF = 0x3f3f3f3f;
int pre[10010];
int N; //顶点数目
int M; //边数目
Point po[10010];

void init()
{
    for (int i = 0; i < 111; i++)
        pre[i] = i;
}
int find(int x)
{
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}

void mix(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        pre[y] = fx;
}

bool cmp(Edge a, Edge b)
{
    if (a.w != b.w)
        return a.w < b.w;
    if (a.u != b.u)
        return a.u < b.u;
    if (a.u != b.v)
        return a.v < b.v;
}
void kruskal()
{
    Edge e[10010];
    int i, j, count;
    double cost;
    bool clear;
    count = 0;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            double jud = sqrt((po[i].x - po[j].x) * (po[i].x - po[j].x) + (po[i].y - po[j].y) * (po[i].y - po[j].y));
            e[count].u = i;
            e[count].v = j;
            if (jud < 10 || jud > 1000)
                e[count++].w = INF;
            else
                e[count++].w = jud;
        }
    }
    // cout << "count: " << count << endl;
    sort(e + 1, e + count + 1, cmp);
    cost = 0;
    for (i = 1; i <= count - 1; i++)
    {
        if (e[i].w != INF && find(e[i].u) != find(e[i].v))
        {
            mix(e[i].u, e[i].v);
            cost += e[i].w;
        }
    }
    clear = true;
    for (i = 2; i <= N; i++)
    {
        if (find(1) != find(i))
        {
            clear = false;
            break;
        }
    }
    if (clear)
        printf("%.1f\n", cost * 100);
    else
        printf("oh\n");
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int i, T; //T组数据
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        init();
        for (i = 1; i <= N; i++)
        {
            scanf("%d%d", &po[i].x, &po[i].y);
        }
        kruskal();
    }
    return 0;
}