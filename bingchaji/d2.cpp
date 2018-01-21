#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int pre[30010];

void init(int len)
{
    // memset(pre, -1, sizeof(int) * len);
    for (int i = 0; i <= len; i++)
    {
        pre[i] = i;
    }
}

int find(int x)
{
    if (pre[x] == x)
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

int main()
{
    int id, lines;
    while (scanf("%d%d", &id, &lines) && (id || lines))
    {
        init(id);
        while (lines--)
        {
            int num_stu, stu1, pre_stu;
            scanf("%d", &num_stu);
            for (int i = 0; i < num_stu; i++)
            {
                scanf("%d", &stu1);
                if (i == 0)
                {
                    pre_stu = stu1;
                }
                join(pre_stu, stu1);
                pre_stu = stu1;
            }
        }
        int ans = 1;
        for (int i = 1; i <= id; i++)
        {
            if (find(0) == find(i))
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}