#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// string s1 = "qwertyuiopasdfghjklzxcvbnm";
// string s2 = "veamhjsgqocnrbfxdtwkylupzi";

int get_index(string s1, char ch)
{
    for (int i = 0; i < s1.length(); i++)
    {
        if (ch == s1[i])
        {
            return i;
        }
    }
}

int main()
{
    string s1, s2, s;
    while (cin >> s1 >> s2 >> s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (int(ch) >= 97 && int(ch) <= 122)
            {
                int index = get_index(s1, ch);
                cout << s2[index];
            }
            else if (int(ch) >= 65 && int(ch) <= 90)
            {
                char ch_low = ch + 32;
                int index = get_index(s1, ch_low);
                cout << char(s2[index] - 32);
            }
            else
            {
                cout << ch;
            }
        }
        cout << "\n";
    }
    return 0;
}