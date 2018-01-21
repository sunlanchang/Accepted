#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 0x3f3f3f3f;
// int visit[maxn];
char letter[maxn];
// int cnt;
string str;
int n, l;

bool hard_str(string str)
{
    int len = str.size();
    for (int i = 1; i <= len / 2; i++)
    {
        string tmpstr1 = str.substr(len - i * 2, i);
        string tmpstr2 = str.substr(len - i, i);
        if (tmpstr1 == tmpstr2)
        {
            return false;
        }
    }
    return true;
}

void dfs(int pos, int cnt)
{
    if (!hard_str(str))
    {
        // cout << "**: " << str << endl;
        return;
    }
    if (cnt == n)
    {
        cout << "str: " << str << endl;
        // cout << "len: " << str.size() << endl;
        return;
    }
    for (int i = 0; i < l; i++)
    {
        str += char('A' + i);
        dfs(i, cnt + 1);
        str = str.substr(0, str.size() - 1);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &l))
    {
        // memset(visit, 0, sizeof(visit));
        // cnt = 0;
        string str = "";
        dfs(0, 0);
    }
    return 0;
}
