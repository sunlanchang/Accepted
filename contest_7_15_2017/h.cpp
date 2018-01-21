#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> get_tail(int n)
{
    vector<int> res;
    for (int i = 1; i <= 9; i++)
    {
        res.push_back(n * i % 10);
    }
    return res;
}

bool exist(vector<int> v, int n)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (n == v[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int price, coin;
    while (scanf("%d%d", &price, &coin) != EOF)
    {
        int price_tail = price % 10;
        vector<int> tail = get_tail(price_tail);
        // for (auto e : tail)
        // {
        //     cout << e << " ";
        // }
        if (exist(tail, coin))
        {
            int i = 1;
            while (price * i % 10 != coin)
            {
                i++;
            }
            cout << i << "\n";
        }
        else
        {
            if (exist(tail, 0))
            {
                int i = 1;
                while (price * i % 10 != 0)
                {
                    i++;
                }
                cout << i << "\n";
            }
            // else
            // {
            //     cout << price / 10 << "\n";
            // }
        }
    }
    return 0;
}