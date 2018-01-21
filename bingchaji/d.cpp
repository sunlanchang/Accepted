#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int pre[50010] = {0};

int findRoot(int x)
{
    int root = x;
    while (root != pre[root])
    {
        root = pre[root];
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

int main()
{
    int id, lines;
    while (cin >> id >> lines && (id || lines))
    {
        for (int i = 0; i < id; i++)
        {
            pre[i] = i;
        }
        int lines_tmp = lines;
        while (lines_tmp--)
        {
            int num_line;
            vector<int> v;
            cin >> num_line;
            for (int j = 0; j < num_line; j++)
            {
                int stu_id;
                cin >> stu_id;
                v.push_back(stu_id);
                if (j >= 1)
                {
                    join_root(v[j], v[j - 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < id; i++)
        {
            if (findRoot(i) == findRoot(0))
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}