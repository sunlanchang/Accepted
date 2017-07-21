#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

//#define ONLINE_JUDGE

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    long _begin_time = clock();
#endif

#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %.2f ms\n", double(_end_time - _begin_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}
