#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int pre[50010] = {0};

int find_root(int x)
{
    int root = x;
    while (root != pre[root])
    {
        root = pre[root];
    }

    // int x_tmp = x, pre_x;
    // while (root != pre[x_tmp])
    // {
    //     pre_x = pre[x_tmp];
    //     pre[x_tmp] = root;
    //     x_tmp = pre_x;
    // }

    return root;
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

int main()
{
    int id_sum, lines, t = 1;
    while (cin >> id_sum >> lines && (id_sum || lines))
    {
        for (int i = 1; i <= id_sum; i++)
        {
            pre[i] = i;
        }
        while (lines--)
        {
            int stu1, stu2;
            cin >> stu1 >> stu2;
            join_root(stu1, stu2);
        }
        map<int, int> m;
        for (int i = 1; i <= id_sum; i++)
        {
            int i_root = find_root(i);
            m[i_root]++;
        }
        map<int, int>::iterator it;
        int ans = m.size();
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}