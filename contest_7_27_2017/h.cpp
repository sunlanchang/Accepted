#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int w;
    while (~scanf("%d", &w))
    {
        if (w <= 2)
        {
            printf("NO\n");
        }
        else
        {
            if (w % 2 == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
