#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
char arr[1000];
int main()
{
    int n;
    freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n))
    {
        getchar(); //吃掉输入数字后的那个回车
        while (n--)
        {
            memset(arr, 0, sizeof(arr));
            gets(arr);
            int cnt = 0;
            for (int i = 0; i < strlen(arr) i++)
                if (arr[i] < 0)
                    cnt++;
            cout << cnt / 2 << endl;
        }
    }
    return 0;
}