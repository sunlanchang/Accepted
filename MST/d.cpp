#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int num[10];
bool idx[10];

void dfs(int n_, int m_)
{
    if (n_ > n)
        return;
    if (m_ == m + 1)
    {
        for (int i = 1; i <= m; i++)
            cout << num[i] << " ";
        cout << "\n";
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (idx[x] == false)
        {
            idx[x] = true;
            num[m_] = x;
            dfs(x, m_ + 1);
            idx[x] = false;
        }
    }
}
void init()
{
    for (int i = 1; i <= n; i++)
        idx[i] = false;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (~scanf("%d%d", &n, &m) && (m || n))
    {
        init();
        dfs(n, 1);
    }
    return 0;
}
