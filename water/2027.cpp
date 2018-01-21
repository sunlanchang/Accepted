#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int n;
int main()
{
    freopen("in.txt", "r", stdin);
    while (~scanf("%d\n", &n))
    {
        while (n--)
        {
            int a = 0, e = 0, ii = 0, o = 0, u = 0;
            char arr[1111];
            gets(arr);
            for (int i = 0; i < strlen(arr); i++)
                if (arr[i] == 'a')
                    a++;
                else if (arr[i] == 'e')
                    e++;
                else if (arr[i] == 'i')
                    ii++;
                else if (arr[i] == 'o')
                    o++;
                else if (arr[i] == 'u')
                    u++;
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, ii, o, u);
            if (n != 0)
                printf("\n");
        }
    }
    return 0;
}
