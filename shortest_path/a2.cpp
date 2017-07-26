#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 110, INF = 0x3f3f3f3f;
int N, M;
int cost[maxn][maxn], minicost[maxn];
bool used[maxn];

void init(int n, int m)
{
    for (int i = 1; i <= m; i++)
    {
        used[i] = false;
        for (int j = 1; j <= m; j++)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
}

int prim()
{
    for (int i = 1; i <= M; i++)
        minicost[i] = cost[1][i];
    used[1] = true;
    int ans = 0;
    for (int i = 2; i <= M; i++)
    {
        int index = -1;
        int minic = INF;
        for (int j = 1; j <= M; j++)
            if (!used[j] && minicost[j] < minic)
                index = j, minic = minicost[j];
        if (index == -1)
            return 0;
        used[index] = true;
        ans += minic;
        for (int k = 1; k <= M; k++)
            if (!used[k])
                minicost[k] = min(minicost[k], cost[index][k]);
    }
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while (~scanf("%d%d", &N, &M) && N)
    {
        init(N, M);
        for (int i = 1; i <= N; i++)
        {
            int t1, t2, t3;
            scanf("%d%d%d", &t1, &t2, &t3);
            cost[t1][t2] = cost[t2][t1] = t3;
        }
        int ans = prim();
        if (ans == 0)
            printf("?\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
