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
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n))
    {
        string n1 = "1", n2 = "1", n3 = "0";
        int cnt = n - 2;
        for (; cnt > 0; cnt--)
        {
            n3 = add(n1, n2);
            n1 = n2, n2 = n3;
        }
        if (n == 1 || n == 2)
            printf("1\n");
        else
            cout << n3 << '\n';
    }
    return 0;
}
