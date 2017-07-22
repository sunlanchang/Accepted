#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int n = 50010;
int pre[n * 3] = {0};

int find_root(int x)
{
    if (pre[x] == x)
    {
        return x;
    }
    return pre[x] = find_root(pre[x]);
}

void join_root(int i, int j)
{
    int i_root = find_root(i);
    int j_root = find_root(j);
    if (i_root != j_root)
    {
        pre[j_root] = i_root;
    }
}

bool same(int i, int j)
{
    return find_root(i) == find_root(j);
}

int main()
{
    int n, K;
    scanf("%d%d", &n, &K);
    for (int cnt = 0; cnt < K; cnt++)
    {
        int lie = 0;
        for (int i = 1; i <= n * 3; i++)
        {
            pre[i] = i;
        }

        int D, x, y;
        while (K--)
        {
            // cin >> D >> x >> y;
            scanf("%d%d%d", &D, &x, &y);
            if (x > n || y > n || x < 1 || y < 1 || (D == 2 && x == y)) //不合法的输入
            {
                lie++;
                continue;
            }
            if (D == 1)
            {
                if (same(x, y + n))
                {
                    lie++;
                }
                else
                {
                    join_root(x, y);
                    join_root(x + n, y + n);
                    join_root(x + 2 * n, y + 2 * n);
                }
            }
            else
            {
                if (same(x, y) || same(x, y + 2 * n)) //如果x和y同一种类或y吃x
                    lie++;
                else
                {
                    join_root(x, y + n); //三种情况为x吃y
                    join_root(x + n, y + 2 * n);
                    join_root(x + 2 * n, y);
                }
            }
        }
        cout << lie << endl;
    }
    return 0;
}