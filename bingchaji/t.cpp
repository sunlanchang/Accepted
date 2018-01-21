#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

const int n = 100010;
int pre[n + n] = {0};

int find(int x)
{
    if (x == pre[x])
    {
        return x;
    }
    return pre[x] = find(pre[x]);
}

void join(int i, int j)
{
    int iRoot = find(i);
    int jRoot = find(j);
    if (iRoot != jRoot)
    {
        pre[jRoot] = iRoot;
    }
}

void init()
{
    for (int i = 1; i <= n + n - 1; i++)
    {
        pre[i] = i;
    }
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

int main()
{
    int Case;
    cin >> Case;
    while (Case--)
    {
        int id_sum, lines;
        cin >> id_sum >> lines;
        init();
        while (lines--)
        {
            char chr;
            int a, b;
            // getchar();
            // scanf("%c%d%d", &chr, &a, &b);
            cin >> chr >> a >> b;
            if (chr == 'A')
            {
                if (same(a, b) || same(a + n, b + n))
                {
                    cout << "In the same gang." << endl;
                }
                else if (same(a, b + n) || same(a + n, b))
                {
                    cout << "In different gangs." << endl;
                }
                else
                {
                    cout << "Not sure yet." << endl;
                }
            }
            else if (chr == 'D')
            {
                join(a, b + n);
                join(a + n, b);
            }
        }
    }
    return 0;
}
