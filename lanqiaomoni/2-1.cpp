#include <iostream>
#include <cstdio>
using namespace std;
void print_num(int n)
{
    for (int i = 6; i >= 0; i--)
    {
        if (n & (1 << i))
            printf("*");
        else
            printf(" ");
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int n, cnt = 0;
    while (~scanf("%d", &n))
    {

        print_num(n);
        if (++cnt % 2 == 0)
            printf("\n");
    }
    return 0;
}