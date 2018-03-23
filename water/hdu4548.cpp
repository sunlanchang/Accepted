#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000010;
int prime[maxn];
int bp[maxn];
int sum_is_prime(int n)
{
    int num_sum = 0;
    while (n > 0)
    {
        num_sum += (n % 10);
        n /= 10;
    }
    if (prime[num_sum])
        return 1;
    return 0;
}
int main()
{
    freopen("in.txt", "r", stdin);
    for (int i = 2; i < maxn; i++)
        prime[i] = 1;
    for (int i = 2; i < maxn; i++)
        if (prime[i] == 1)
            for (int j = i + i; j < maxn; j += i)
                prime[j] = 0;
    memset(bp, 0, sizeof(bp));
    bp[1] = 0;
    int num = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (prime[i] && sum_is_prime(i))
            bp[i] = ++num;
        else
            bp[i] = num;
    }
    int T, case_ = 0;
    scanf("%d", &T);
    while (T--)
    {
        int L, R, cnt = 0;
        scanf("%d%d", &L, &R);
        printf("Case #%d: %d\n", ++case_, bp[R] - bp[L - 1]);
    }
    return 0;
}