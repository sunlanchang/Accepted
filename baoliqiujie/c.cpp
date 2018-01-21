#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int k;
    while (~scanf("%d", &k))
    {
        vector<int> X, Y;
        for (int y = k + 1; y <= 2 * k; y++)
        {
            if (0 == k * y % (y - k) && y != k)
            {
                int x = k * y / (y - k);
                X.push_back(x);
                Y.push_back(y);
            }
        }
        printf("%lu\n", X.size());
        for (int i = 0; i < X.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k, X[i], Y[i]);
    }
    return 0;
}
