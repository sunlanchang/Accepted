#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

ll Power(ll a, ll n, ll m)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = ans * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return ans;
}

bool is_prime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll n;
    while (scanf("%lld", &n) && n)
    {
        bool is_carm = true;
        if (is_prime(n))
        {
            is_carm = false;
        }
        else
        {
            for (ll a = 2; a < n; a++)
            {
                if (a != Power(a, n, n))
                {
                    is_carm = false;
                    break;
                }
            }
        }
        if (is_carm)
        {
            printf("The number %lld is a Carmichael number.\n", n);
        }
        else
        {
            printf("%lld is normal.\n", n);
        }
    }
    return 0;
}