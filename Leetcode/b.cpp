#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

vector<int> constructArray(int n, int k)
{
    vector<int> res;
    for (int i = 1, j = n; i <= j;)
    {
        if (k > 1)
        {
            if (k % 2 == 0)
                res.push_back(i++);
            else
                res.push_back(j--);
            k--;
        }
        else
        {
            if (k % 2 == 0)
                res.push_back(i++);
            else
                res.push_back(j--);
        }
    }
    return res;
}

int main()
{
    freopen("in.txt", "r", stdin);
    constructArray(5, 2);
    return 0;
}
