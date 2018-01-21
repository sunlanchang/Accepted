#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
bool judgeCircle(string moves)
{
    int res1 = 0, res2 = 0;
    for (int i = 0; i < moves.length(); i++)
    {
        if (moves[i] == 'U')
            res1++;
        else if (moves[i] == 'D')
            res1--;
        else if (moves[i] == 'L')
            res2--;
        else if (moves[i] == 'R')
            res2++;
    }
    if (!res1 && !res2)
        return true;
    else
        return false;
}
int main()
{
    freopen("in.txt", "r", stdin);
    string moves;
    while (cin >> moves)
    {
        judgeCircle(moves);
    }
    return 0;
}
