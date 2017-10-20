#include <iostream>
#include <cstdio>

using namespace std;

int close_compare(int a, int b, int margin)
{
    int x;
    if (a - b <= 0)
        x = b - a;
    else
        x = a - b;
    if (x <= margin)
        return 0;
    else
        a < b ? -1 : 1;
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    close_compare(a, b, m);
    return 0;
}