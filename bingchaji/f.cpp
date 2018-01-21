#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 100010;
int pre[MAX];

void init(int len)
{
    memset(pre, -1, sizeof(int) * len);
}

int find(int x)
{
    if (pre[x] < 0)
    {
        return x;
    }
    return pre[x] = find(pre[x]);
}

void mix(int i, int j)
{
    int iRoot = find(i);
    int jRoot = find(j);
    if (iRoot != jRoot)
    {
        pre[jRoot] = iRoot;
    }
}

bool same(int i, int j)
{
    return find(i) == find(j);
}

int main()
{
    while (true)
    {
        int a, b, num_set = 0;
        bool is_same = false;
        vector<int> v;
        init(MAX);
        while (scanf("%d%d", &a, &b) && (a != -1 && b != -1))
        {
            if (a == 0 && b == 0)
            {
                break;
            }
            v.push_back(a);
            v.push_back(b);
            if (same(a, b))
            {
                is_same = true;
            }
            else
            {
                mix(a, b);
            }
        }
        if (a == -1 && b == -1)
        {
            break;
        }
        for (int i = 1; i < v.size(); i++)
        {
            if (find(v[i]) != find(v[0]))
            {
                num_set++;
            }
        }
        if (is_same || num_set >= 2)
        {
            // cout << "is same: " << is_same << endl;
            // cout << "num_set: " << num_set << endl;
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}