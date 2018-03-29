//answer 897
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (i != j && i != k && j != k)
                {
                    int res = (i * 100 + j * 10 + k) * (i * 100 + j * 10 + k);
                    if (res < 100000)
                        continue;
                    int first = res / 100000, last = res % 10;
                    int second = res / 10000 % 10, last_second = res / 10 % 10;
                    int mid_first = res / 1000 % 10, mid_seccond = res / 100 % 10;
                    if (i == first && j == last && second == last_second)
                        cout << i * 100 + j * 10 + k << endl;
                }
    return 0;
}