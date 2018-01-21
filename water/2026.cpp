#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
char arr[111];
int main()
{
    while (gets(arr))
    {
        printf("%c", arr[0] - 32);
        for (int i = 1; i < strlen(arr); i++)
            if (arr[i] == ' ')
                printf(" %c", arr[++i] - 32);
            else
                printf("%c", arr[i]);
        printf("\n");
    }
    return 0;
}
