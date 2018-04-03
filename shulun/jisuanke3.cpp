#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1111;
bool prime[maxn];
void init()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i < maxn; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * 2; j < maxn; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
int main()
{
    int n;
    init();
    scanf("%d", &n);
    if (prime[n])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}