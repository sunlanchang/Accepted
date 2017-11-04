#include <cstdio>
using namespace std;
int n, m;
double arr[55][55];
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m))
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            double aves = 0;
            for (int j = 0; j < m; j++)
            {
                scanf("%lf", &arr[i][j]);
                aves += arr[i][j];
            }
            printf("%.2lf%c", aves / m, i == n - 1 ? '\n' : ' ');
        }
        for (int j = 0; j < m; j++)
        {
            double avec = 0;
            for (int i = 0; i < n; i++)
                avec += arr[i][j];
            arr[n][j] = avec / n;
            printf("%.2lf%c", avec / n, j == m - 1 ? '\n' : ' ');
        }
        for (int i = 0; i <= n; i++)
        {
            bool flag = false;
            for (int j = 0; j < m; j++)
                if (arr[i][j] < arr[n][j])
                {
                    flag = true;
                    break;
                }
            if (!flag)
                cnt++;
        }
        printf("%d\n\n", cnt - 1);
    }
    return 0;
}
