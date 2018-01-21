#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int num[33], n;

int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n))
    {
        num[1] = 1;
        for (int i = 2; i <= n; i++)
            num[i] = 2 * (num[i - 1] + 1);
        printf("%d\n", num[n]);
    }
    return 0;
}
