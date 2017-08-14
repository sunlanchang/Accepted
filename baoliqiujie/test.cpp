#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    string s;
    s = "abc";
    s = s.substr(0, s.size() - 1);
    cout << s << endl;
    return 0;
}
