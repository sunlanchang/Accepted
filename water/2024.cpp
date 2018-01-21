#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int n;
char arr[50];
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n))
    {
        getchar();
        while (n--)
        {
            gets_s(arr);
            if (!isalpha(arr[0]) && arr[0] != '_')
            {
                printf("no\n");
                continue;
            }
            bool flag = false;
            for (int i = 1; i < strlen(arr); i++)
                if (!isalpha(arr[i]) && !isdigit(arr[i]) && arr[i] != '_')
                    flag = true;
            if (!flag)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
