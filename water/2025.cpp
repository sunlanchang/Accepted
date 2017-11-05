#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
char arr[111];
string inst = "(max)";
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%s", &arr))
    {
        char maxchr = 'a' - 1;
        for (int i = 0; i < strlen(arr); i++)
            if (arr[i] > maxchr)
                maxchr = arr[i];
        for (int i = 0; i < strlen(arr); i++)
        {
            printf("%c", arr[i]);
            if (arr[i] == maxchr)
                cout << inst;
            if (i == strlen(arr) - 1)
                printf("\n");
        }
    }
    return 0;
}
