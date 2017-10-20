#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
int f[7654][543];
int main()
{
    // freopen("in.txt", "r", stdin);
    //模拟大整数，前四位是低位，后四位是高位，例如数组存储了12,3456,78应当从后向前读:7834560012，注意模拟的除了第一个低位其余位不够四位补零。
    f[0][0] = f[1][0] = f[2][0] = f[3][0] = 1;
    for (int i = 4; i < 7654; i++)
    {
        int tmp = 0;
        for (int j = 0; j < 543; j++)
        {
            tmp += f[i - 4][j] + f[i - 3][j] + f[i - 2][j] + f[i - 1][j];
            f[i][j] = tmp % 10000;
            tmp /= 10000;
        }
    }
    int n;
    while (~scanf("%d", &n))
    {
        int i = 543 - 1;
        for (; i >= 0; i--)
            if (f[n][i] > 0)
                break;
        //第一个低四位不用补零
        printf("%d", f[n - 1][i]);
        //其余位不够四位补零
        for (int j = i - 1; j >= 0; j--)
            printf("%04d", f[n - 1][j]);
        printf("\n");
    }
    return 0;
}
