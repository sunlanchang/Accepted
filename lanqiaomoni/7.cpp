#include <iostream>  // std::cout
#include <algorithm> // std::next_permutation, std::sort
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    string str = "aaabbbbccccc";
    vector<string> v;
    int cnt = 0;
    do
    {
        bool flag = true;
        for (int i = 0; i < v.size(); i++)
            if (v[i].find(str) != string::npos)
            {
                flag = false;
                break;
            }
        if (!flag)
            continue;
        string str2 = str + str;
        v.push_back(str2);
        string str_rev;
        for (int i = str2.size() - 1; i >= 0; i--)
            str_rev += str2[i];
        v.push_back(str_rev);
        cnt++;
    } while (next_permutation(str.begin(), str.end()));
    cout << cnt << endl;
    return 0;
}