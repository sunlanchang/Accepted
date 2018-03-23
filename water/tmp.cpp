#include <stdio.h>
#define N 1000001
int prime[N];
int main()
{
    freopen("in.txt", "r", stdin);
    for (int j = 0; j < N; j++)
        prime[j] = -1;
    int num = 0;
    for (int i = 2; i < N; i++)
    {
        if (prime[i] == -1)
        {
            num++;
            for (int j = i; j < N; j += i)
                prime[j] = num;
        }
    }

    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 1)
            printf("0\n");
        else
            printf("%d\n", prime[n]);
    }
    return 0;
}