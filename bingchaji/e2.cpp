#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

const int N = 100010;
int pre[N + N] = {0};

int findRoot(int x)
{
    int root = x;
    while (root != pre[root])
    {
        root = pre[root];
    }
    int x_tmp = x, pre_x;
    while (root != pre[x_tmp])
    {
        pre_x = pre[x_tmp];
        pre[x_tmp] = root;
        x_tmp = pre_x;
    }
    return root;
}

void join_root(int i, int j)
{
    int iRoot = findRoot(i);
    int jRoot = findRoot(j);
    if (iRoot != jRoot)
    {
        pre[jRoot] = iRoot;
    }
}

void init()
{
    for (int i = 1; i <= N + N - 1; i++)
    {
        pre[i] = i;
    }
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
            int id1, id2;
            cin >> chr >> id1 >> id2;
            // getchar();
            // scanf("%c%d%d", &chr, &id1, &id2);
            if (chr == 'A')
            {
                if (findRoot(id1) != findRoot(id2) && findRoot(id1) != findRoot(id2 + N))
                {
                    cout << "Not sure yet." << endl;
                }
                else if (findRoot(id1) == findRoot(id2))
                {
                    cout << "In the same gang." << endl;
                }
                else
                {
                    cout << "In different gangs." << endl;
                }
            }
            else if (chr == 'D')
            {
                join_root(id1, id2 + N);
                join_root(id1 + N, id2);
            }
        }
    }
    return 0;
}