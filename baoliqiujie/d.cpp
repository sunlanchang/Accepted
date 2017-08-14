#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
int num[20];
bool idx[20];
int kase = 1;

bool isPrime(int number)
{
    for (int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;
    return true;
}

void solve()
{
    for (int i = 0; i < n; i++)
        printf("%d%c", num[i], i == n - 1 ? '\n' : ' ');
}

void dfs(int n_, int m_)
{
    if (m_ == m + 1 && isPrime(num[0] + num[n - 1]))
    {
        solve();
        return;
    }
    for (int x = 2; x <= n; x++)
    {
        if (idx[x] == false && isPrime(x + num[m_ - 1]))
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
    num[0] = 1;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    bool tmp = false;
    while (~scanf("%d", &n))
    {
        m = n - 1;
        init();
        if (tmp)
            printf("\n");
        tmp = true;
        printf("Case %d:\n", kase++);
        dfs(0, 1);
    }
    return 0;
}