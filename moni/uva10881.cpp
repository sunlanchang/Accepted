#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 10011;
struct ant
{
    int x, id;
    char dir;
    ant() { id = 0; }
};
struct pos
{
    int id, order;
};
ant X[maxn], arr[maxn];
pos out_order[maxn];
int L, T, N;
bool cmp(ant a, ant b)
{
    return a.x < b.x;
}
bool cmp2(pos a, pos b)
{
    return a.id < b.id;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int cases;
    scanf("%d", &cases);
    int Case = 0;
    while (cases--)
    {
        scanf("%d%d%d", &L, &T, &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d %c", &arr[i].x, &arr[i].dir);
            X[i].x = arr[i].x, X[i].dir = arr[i].dir;
            X[i].id = i;
        }
        sort(X, X + N, cmp);
        for (int i = 0; i < N; i++)
        {
            out_order[i].order = i;
            out_order[i].id = X[i].id;
        }
        sort(out_order, out_order + N, cmp2);
        for (int i = 0; i < N; i++)
        {
            if (arr[i].dir == 'R')
                arr[i].x += T;
            else
                arr[i].x -= T;
        }
        sort(arr, arr + N, cmp);
        for (int i = 0; i < N; i++)
        {
            if (arr[i].x < 0 || arr[i].x > L)
                arr[i].dir = 'F';
            else if (i + 1 < N && arr[i].x == arr[i + 1].x)
                arr[i].dir = 'T', arr[++i].dir = 'T';
        }
        printf("Case #%d:\n", ++Case);
        for (int j = 0; j < N; j++)
        {
            int i = out_order[j].order;
            if (arr[i].dir == 'F')
                printf("Fell off\n");
            else if (arr[i].dir == 'T')
                printf("%d Turning\n", arr[i].x);
            else
                printf("%d %c\n", arr[i].x, arr[i].dir);
        }
        printf("\n");
    }
    return 0;
}