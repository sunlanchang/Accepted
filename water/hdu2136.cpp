#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 10000010;
int arr[maxn];
int main()
{
    freopen("in.txt", "r", stdin);
    arr[1] = 0;
    for (int i = 2; i < maxn; i++)
        arr[i] = -1;
    // int number = 2;
    for (int i = 2; i < maxn; i++)
    {
        if (arr[i] == -1)
        {
            for (int j = i; j < maxn; j += i)
            {
                arr[j] = i;
            }
            // number++;
        }
    }
    // for (int i = 0; i < 20; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    int n;
    while (~scanf("%d", &n))
    {
        cout << arr[n] << endl;
    }
    return 0;
}