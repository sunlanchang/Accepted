#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
int main()
{
    int x[9] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int N = 9;
    int num = 1, cur = 0, last = 0;
    int mid = 3, i = 0;
    while (i < N)
    {
        if (x[cur] - x[last] >= mid)
        {
            num++;
            last = cur;
            cout << "cur: " << cur << endl;
        }
        i++;
        cur = i;
    }
    cout << "num: " << num << endl;
    return 0;
}