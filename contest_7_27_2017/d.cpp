#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 210000, INF = 0x3f3f3f3f;
int n[maxn];
int num;

int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d", &num))
    {
        memset(n, 0, sizeof(n));
        string str;
        bool flag = false;
        int ans = 0;
        cin >> str;
        for (int i = 0; i < num; i++)
            scanf("%d", &n[i]);
        if (str.find("RL") != string::npos)
        {
            int pos = 0;
            int ans = INF;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == 'R' && str[i + 1] == 'L')
                {
                    pos = i;
                    if (n[pos + 1] - n[pos] < ans)
                    {
                        ans = n[pos + 1] - n[pos];
                    }
                    i++;
                }
            }
            if (ans % 2 == 0)
                printf("%d\n", ans / 2);
            else
                printf("%d\n", ans / 2 + 1);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
