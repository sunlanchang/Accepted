#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const long long int maxn = 99999999;
bool prime[maxn];
int num[maxn];
int main()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    int number = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (prime[i] == true)
        {
            num[number++] = i;
            for (int j = i + i; j < maxn; j += i)
                prime[j] = false;
        }
    }
    for (int gongcha = 1; gongcha < 1000; gongcha++)
    {
        for (int start = 2; start < maxn; start++)
        {
            int ans = 0, flag = 1;
            for (int j = 0; j <= 12; j++)
            {
                if (prime[start + j * gongcha])
                    ans++;
                else
                {
                    flag = 0;
                    break;
                }
                if (flag && ans == 12)
                {
                    cout << start << " " << gongcha << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}