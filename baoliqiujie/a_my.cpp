#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int num[10];
bool idx[10], has_ans;
int N;

void solve()
{
    int number1 = 0, t = 10000;
    for (int i = 0; i < 5; i++)
    {
        number1 += t * num[i];
        t /= 10;
    }
    int number2 = number1 * N;
    char buff[100];
    sprintf(buff, "%05d%05d", number1, number2);
    if (strlen(buff) > 10)
        return;
    sort(buff, buff + 10);
    bool ok = true;
    for (int i = 0; i < 10; i++)
        if (buff[i] != '0' + i)
            ok = false;
    if (ok)
        printf("%05d / %05d = %d\n", number2, number1, N), has_ans = true;
}

void dfs(int n_, int m_)
{
    if (m_ == m)
    {
        solve();
        return;
    }
    for (int x = 0; x <= n; x++)
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
    // freopen("in.txt", "r", stdin);
    bool tmp = false;
    while (~scanf("%d", &N) && N)
    {
        n = 9, m = 5;
        init();
        has_ans = false;
        if (tmp)
            printf("\n");
        tmp = true;
        dfs(n, 0);
        if (!has_ans)
            printf("There are no solutions for %d.\n", N);
    }
    return 0;
}