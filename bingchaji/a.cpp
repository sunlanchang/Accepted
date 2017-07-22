#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int pre[50010] = {0};

int find(int x)
{
    if (pre[x] == x)
    {
        return x;
    }
    return pre[x] = find(pre[x]);
}

void join_root(int i, int j)
{
    int i_root = find(i);
    int j_root = find(j);
    if (i_root != j_root)
    {
        pre[j_root] = i_root;
    }
}

void init(int id_sum)
{
    for (int i = 1; i <= id_sum; i++)
    {
        pre[i] = i;
    }
}

int main()
{
    int id_sum, lines, t = 1;
    while (scanf("%d%d", &id_sum, &lines) && (id_sum || lines))
    {
        init(id_sum);
        while (lines--)
        {
            int stu1, stu2;
            cin >> stu1 >> stu2;
            join_root(stu1, stu2);
        }
        map<int, int> m;
        for (int i = 1; i <= id_sum; i++)
        {
            int i_root = find(i);
            m[i_root]++;
        }
        map<int, int>::iterator it;
        int ans = m.size();
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}