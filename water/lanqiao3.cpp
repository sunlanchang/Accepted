#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double arr[30][30];
    freopen("in.txt", "r", stdin);
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < i; j++)
        {
            scanf("%lf", &arr[i][j]);
        }
    }
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < i; j++)
        {
                }
        cout << endl;
    }
    // cout << arr[0][0] << endl;
    return 0;
}