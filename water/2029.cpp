#include <string.h>
#include <cstdio>
#include <iostream>
using namespace std;
char arr[11111];
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n))
    {
        getchar();
        for (int i = 0; i < n; i++)
        {
            memset(arr, 0, sizeof(arr));
            gets(arr);
            int len = strlen(arr);
            int flag = 1;
            for (int j = 0; j < len / 2; j++)
            {
                if (arr[j] != arr[len - 1 - j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
