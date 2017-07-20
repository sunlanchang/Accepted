#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

#define ONLINE_JUDGE

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long _begin_time = clock();
#endif

#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %ld ms\n", _end_time - _begin_time);
#endif
    return 0;
}
