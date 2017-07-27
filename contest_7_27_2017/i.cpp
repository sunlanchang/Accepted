#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 150, INF = 0x3f3f3f3f;
int cost[maxn][maxn], minicost[maxn];
int M;
bool used[maxn];

void init()
{
    for (int i = 1; i <= M; i++)
        used[i] = false;
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
    while (~scanf("%d", &M) && M)
    {
        init();
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &cost[i][j]);
        int ans = prim();
        if (ans != 0)
            printf("%d\n", ans);
    }
    return 0;
}
