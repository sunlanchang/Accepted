#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int arr[999999];
int a[111], res[111];
int main()
{
    freopen("in.txt", "r", stdin);
    int m, n;
    while (~scanf("%d%d", &m, &n) && (m || n))
    {
        memset(arr, 0x3f, sizeof(arr));
        memset(a, 0, sizeof(a));
        memset(res, 0, sizeof(res));
        for (int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            arr[tmp] = 1;
        }
        int length_inc = 0;
        for (int i = 0; i < m; i++)
            if (arr[a[i]] != 1)
                res[length_inc++] = a[i];
        if (length_inc == 0)
        {
            printf("NULL\n");
            continue;
        }
        sort(res, res + length_inc);
        for (int i = 0; i < length_inc; i++)
            printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}