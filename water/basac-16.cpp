#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int maxn = 0x3f3f3f3f;
char arr[11111], oct_num[99999999];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", &arr);
        int dec_num = 0, cishu = 0;
        for (int i = strlen(arr) - 1; i >= 0; i--)
        {
            int tmp_num = arr[i] - '0';
            if (arr[i] >= 'A' && arr[i] <= 'F')
                tmp_num = arr[i] - 'A' + 10;
            dec_num += tmp_num * int(pow(16, cishu++));
        }
        if (dec_num == 0)
        {
            printf("0\n");
            continue;
        }
        int m = dec_num, len = 1;
        while (m != 0)
        {
            oct_num[len++] = m % 8;
            m /= 8;
        }
        for (int i = len - 1; i >= 1; i--)
        {
            printf("%d", oct_num[i]);
        }
        printf("\n");
        memset(arr, 0, sizeof(arr));
        memset(oct_num, 0, sizeof(oct_num));
    }
    return 0;
}
