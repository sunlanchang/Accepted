#include <cstdio>
using namespace std;
int n, mon[] = {100, 50, 10, 5, 2, 1};
int main()
{
    while (~scanf("%d", &n) && n)
    {
        int sum = 0, m;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            for (int j = 0; j < 6; j++)
            {
                sum += (m / mon[j]);
                m %= mon[j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
