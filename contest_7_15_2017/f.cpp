#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct ice
{
    int x;
    int y;
    int r;
};

ice pre[1010];

void init(int len)
{
    // memset(pre, -1, sizeof(int) * len);
    for (int i = 0; i <= len; i++)
    {
        pre[i].r = i;
    }
}

int find(ice x)
{
    if (pre[x.r].r == x.r)
    {
        return x.r;
    }
    return pre[x.r].r = find(pre[x.r]);
}

void join(ice i, ice j)
{
    int iRoot = find(i);
    int jRoot = find(j);
    if (iRoot != jRoot)
    {
        pre[jRoot].r = iRoot;
    }
}

int main()
{
    int cas;
    while (scanf("%d", &cas) != EOF)
    {
        init(cas);
        vector<ice> v;
        for (int i = 0; i < cas; i++)
        {
            int x, y;
            ice t;
            scanf("%d%d", &x, &y);
            t.x = x;
            t.y = y;
            t.r = i;
            v.push_back(t);
            // pre[i] = t;
            if (i > 0)
            {
                for (int j = 0; j < v.size(); j++)
                {
                    if (v[j].x == t.x || v[j].y == t.y)
                    {
                        join(v[j], t);
                    }
                }
            }
        }
        map<int, int> m;
        for (int i = 0; i < v.size(); i++)
        {
            int i_root = find(v[i]);
            m[i_root]++;
        }
        // map<int, int>::iterator it;
        cout << m.size() - 1 << endl;
    }
    return 0;
}