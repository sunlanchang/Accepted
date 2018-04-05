#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void print_num(int n)
{
    vector<int> v;
    if (n > 0)
        v.push_back(0);
    else
    {
        n = -n;
        v.push_back(1);
    }
    while (n > 0)
    {
        v.push_back(n % 2);
        n /= 2;
    }
    if (v[0])
        printf("*");
    else
        printf(" ");
    for (int i = v.size() - 1; i > 0; i--)
    {
        if (v[i])
            printf("*");
        else
            printf(" ");
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n, cnt = 0;
    // print_num(-3);
    while (~scanf("%d", &n))
    {

        print_num(n);
        if (++cnt % 2 == 0)
            printf("\n");
    }
    return 0;
}