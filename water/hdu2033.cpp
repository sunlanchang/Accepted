#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int arr[20];
        for (int i = 1; i <= 6; i++)
            scanf("%d", &arr[i]);
        arr[9] = (arr[3] + arr[6]) % 60;
        arr[8] = ((arr[3] + arr[6]) / 60 + arr[2] + arr[5]) % 60;
        arr[7] = arr[1] + arr[4] + ((arr[3] + arr[6]) / 60 + arr[2] + arr[5]) / 60;
        cout << arr[7] << " " << arr[8] << " " << arr[9] << endl;
    }
    return 0;
}