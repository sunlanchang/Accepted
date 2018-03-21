#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int arr[1000];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int cnt = 0;
        memset(arr, 0, sizeof(arr));
        while (~scanf("%d", &cnt))
        {
            for (int i = 0; i < cnt; i++)
                scanf("%d", &arr[i]);
            sort(arr, arr + cnt);
            int mid = cnt / 2;
            int res = 0;
            for (int i = 0; i < cnt; i++)
            {
                res += abs(arr[i] - arr[mid]);
            }
            cout << res << endl;
        }
    }
    return 0;
}