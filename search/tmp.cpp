#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    freopen("out.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    double money, sum, sale;
    while (~scanf("%lf %lf", &money, &sale))
    {
        sum += money * sale * 0.01;
    }
    cout << sum << endl;
    return 0;
}
