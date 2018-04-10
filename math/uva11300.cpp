#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long int ll;
const ll maxn = 1000001;
ll arr[maxn], cnt[maxn];
ll sum = 0, N;
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%lld", &N))
    {
        sum = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }
        ll avg = sum / N;
        cnt[1] = 0;
        for (int i = 2; i <= N; i++)
            cnt[i] = cnt[i - 1] + avg - arr[i];
        sort(cnt + 1, cnt + 1 + N);
        ll x1 = cnt[(N + 1) / 2];
        ll ans = 0;
        for (int i = 1; i <= N; i++)
            ans += abs(x1 - cnt[i]);
        printf("%lld\n", ans);
    }
    return 0;
}