#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int pre[100000] = {0};

int find_root(int x)
{
    int index = x;
    while (index != pre[index])
    {
        index = pre[index];
    }
    return index;
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
    int city, road;
    while (cin >> city && city)
    {
        cin >> road;
        for (int i = 1; i <= city; i++)
        {
            pre[i] = i;
        }
        int road_tmp = road;
        while (road_tmp--)
        {
            int city_first, city_second;
            cin >> city_first >> city_second;
            join_root(city_first, city_second);
        }
        map<int, int> m;
        for (int i = 1; i <= city; i++)
        {
            int i_root = find_root(i);
            m[i_root]++;
        }
        map<int, int>::iterator it;
        cout << m.size() - 1 << endl;
    }
    return 0;
}