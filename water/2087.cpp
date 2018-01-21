#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
char arr[1111], sub[1111];
int main()
{
    freopen("in.txt", "r", stdin);
    while (~scanf("%s", &arr))
    {
        memset(arr, 0, sizeof(arr));
        memset(sub, 0, sizeof(sub));
        if (arr[0] == '#')
            break;
        scanf("%s", &sub);
        int cnt = 0;
        for (int i = 0; i < strlen(arr); i++)
        {
            int flag = 1;
            for (int j = i, k = 0; (j < i + strlen(sub)) && k < strlen(sub); j++, k++)
            {
                if (sub[k] != arr[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
