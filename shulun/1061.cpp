#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
ll extend_gcd(ll a, ll b, ll &x, ll &y) //扩展欧几里得,求ax+by=gcd(a,b)
{
    ll d = a;
    if (b != 0)
    {
        d = extend_gcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;
        y = 0;
    }
    return d;
}
ll linear(ll a, ll b, ll c) //一元线性同余方程ax=b(mod c)
{
    ll x, y;
    ll g = extend_gcd(a, c, x, y);
    if (b % g)
    {

        return -1;
    }
    x = x * (b / g);
    ll mod = c / g;
    x = (x % mod + mod) % mod;
    return x;
}
ll x, y, m, n, l;
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l))
    {
        ll A = n - m, B = x - y, C = l;
        ll ans = linear(A, B, C);
        if (ans == -1)
            printf("Impossible\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}