#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
const int maxn = 1111;
bool vst[maxn * 1000];
int m, n;
using namespace std;
struct point
{
    int num, cnt;
    point()
    {
        num = cnt = 0;
    }
};
int bfs()
{
    memset(vst, false, sizeof(vst));
    queue<point> q;
    point now, tmp;
    now.num = m, now.cnt = 0;
    q.push(now);
    vst[now.num] = true;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (now.num == n)
            return now.cnt;
        tmp.num = now.num * 2;
        tmp.cnt = now.cnt;
        if (tmp.num > 0 && tmp.num < n * 3 && !vst[tmp.num])
        {
            tmp.cnt = now.cnt + 1;
            q.push(tmp);
            vst[tmp.num] = true;
        }
        tmp.num = now.num - 1;
        tmp.cnt = now.cnt;
        if (tmp.num > 0 && tmp.num < n * 3 && !vst[tmp.num])
        {
            tmp.cnt = now.cnt + 1;
            q.push(tmp);
            vst[tmp.num] = true;
        }
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &m, &n))
    {
        if (m >= n)
            printf("%d\n", m - n);
        else
            printf("%d\n", bfs());
    }
    return 0;
}