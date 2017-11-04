#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 0x3f3f3f;
// const int maxn = 100;
int n, m[maxn];
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n) && n != 0)
    {
        memset(m, 0, sizeof(m));
        int len2 = 1, len1 = 1;
        m[1] = 4;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= len1; i++)
            {

                if (m[i] == 4)
                {
                    m[++len2]++;
                }
                else
                {
                    if (m[i] == 4)
                    {
                        m[++len2]++;
                    }
                    else
                    {
                        m[i]++;
                    }
                }
            }
            len1 = len2;
            // for (int i = 1; i < 10; i++)
            // {
            //     cout << m[i] << ' ';
            // }
            // cout << endl;
        }
        cout << "len: " << len2 - 1 << endl;
        // printf("%d\n", len2 - 1);
    }
    return 0;
}