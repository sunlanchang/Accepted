#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 111111;
bool prime[maxn];
void get_prime()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i < maxn; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i + i; j < maxn; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
int main()
{
    //  freopen("in.txt", "r", stdin);
    get_prime();
    int m, n;
    while (~scanf("%d%d", &m, &n) && (m || n))
    {
        int flag = 1, res = 0;
        for (int i = m; i <= n; i++)
        {
            res = i * i + i + 41;
            if (prime[res] == false)
            {
                printf("Sorry\n");
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("OK\n");
    }
    return 0;
}