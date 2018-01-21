#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

struct Node
{
    int x, y;
    Node(int x = 0, int y = 0) : x(x), y(y) {}
};

const int INF = 0x3f3f3f3f;
Node nodes[150];
bool visit[110];
double cost[150][150], minicost[150];
int num;

void init(int num)
{
    for (int i = 1; i <= num; i++)
    {
        visit[i] = false;
        for (int j = 1; j <= num; j++)
            cost[i][j] = INF;
    }
}

double prim()
{
    for (int i = 1; i <= num; i++)
        minicost[i] = cost[1][i];
    visit[1] = true;
    double ans = 0;
    for (int i = 2; i <= num; i++)
    {
        int index = -1;
        double minic = INF;
        for (int j = 1; j <= num; j++)
            if (!visit[j] && minic > minicost[j])
                minic = minicost[j], index = j;
        if (index == -1)
            return -1;
        visit[index] = true;
        ans += minic;
        for (int j = 1; j <= num; j++)
            if (!visit[j])
                minicost[j] = min(minicost[j], cost[index][j]);
    }
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
        init(num);
        for (int i = 1; i <= num; i++)
            scanf("%d%d", &nodes[i].x, &nodes[i].y);
        for (int i = 1; i <= num; i++)
            for (int j = 1; j <= num; j++)
            {
                Node node_i = nodes[i];
                Node node_j = nodes[j];
                double t = sqrt((node_i.x - node_j.x) * (node_i.x - node_j.x) + (node_i.y - node_j.y) * (node_i.y - node_j.y));
                if (t > 1000 || t < 10)
                    cost[i][j] = cost[j][i] = INF;
                else
                    cost[i][j] = cost[j][i] = t;
            }
        double ans = prim();
        if (ans == -1)
            printf("oh!\n");
        else
            printf("%.1f\n", ans);
    }
    return 0;
}
