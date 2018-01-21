#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

// #define ONLINE_JUDGE

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long _begin_time = clock();
#endif
    for (int i = 0; i < 10; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n", a);
    }
#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %ld ms\n", _end_time - _begin_time);
#endif
    return 0;
}