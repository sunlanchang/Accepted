#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
string add(string str1, string str2) //高精度加法
{
    string str;

    int len1 = str1.length();
    int len2 = str2.length();
    //前面补0，弄成长度相同
    if (len1 < len2)
    {
        for (int i = 1; i <= len2 - len1; i++)
            str1 = "0" + str1;
    }
    else
    {
        for (int i = 1; i <= len1 - len2; i++)
            str2 = "0" + str2;
    }
    len1 = str1.length();
    int cf = 0;
    int temp;
    for (int i = len1 - 1; i >= 0; i--)
    {
        temp = str1[i] - '0' + str2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp + '0') + str;
    }
    if (cf != 0)
        str = char(cf + '0') + str;
    return str;
}
string res[7654];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    res[1] = res[2] = res[3] = res[4] = "1";
    string n1 = "1", n2 = "1", n3 = "1", n4 = "1", n5 = "0";
    for (int i = 5; i < 7649; i++)
    {
        string temp = "0";
        n5 = add(add(n1, n2), add(n3, n4));
        n1 = n2, n2 = n3, n3 = n4, n4 = n5;
        res[i] = n5;
    }
    while (~scanf("%d", &n))
    {
        // for (int i = 1; i < 10; i++)
        //     cout << res[i] << " ";
        // cout << endl;
        cout << res[n] << '\n';
    }
    return 0;
}
