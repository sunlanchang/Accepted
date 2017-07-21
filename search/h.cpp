#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

//#define ONLINE_JUDGE

int N, M;
char m[500][500];
int pre[500][500];

void init(int N, int M)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            m[i][j] = '0';
            pre[i][j] = i * 10 + j;
        }
    }
}
void Unite(int i, int j, int ii, int jj)
{
    ;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    long _begin_time = clock();
#endif
    while (~scanf("%d%d", &N, &M) && N && M)
    {
        init(N, M);
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                scanf("%c", &m[i][j]);
            }
        }
    }
#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %ld ms\n", _end_time - _begin_time);
#endif
    return 0;
}
