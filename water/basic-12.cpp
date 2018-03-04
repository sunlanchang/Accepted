#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// char str[111111];
int a[111111];
string str_1 = "";
string str;
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    while (cin >> n)
    {
        while (n--)
        {
            // scanf("%s", &str);
            cin >> str;
            str_1 = "";
            for (int i = 0; i < str.length(); i++)
            {
                switch (str[i])
                {
                case '0':
                    str_1 += "0000";
                    break;
                case '1':
                    str_1 += "0001";
                    break;
                case '2':
                    str_1 += "0010";
                    break;
                case '3':
                    str_1 += "0011";
                    break;
                case '4':
                    str_1 += "0100";
                    break;
                case '5':
                    str_1 += "0101";
                    break;
                case '6':
                    str_1 += "0110";
                    break;
                case '7':
                    str_1 += "0111";
                    break;
                case '8':
                    str_1 += "1000";
                    break;
                case '9':
                    str_1 += "1001";
                    break;
                case 'A':
                    str_1 += "1010";
                    break;
                case 'B':
                    str_1 += "1011";
                    break;
                case 'C':
                    str_1 += "1100";
                    break;
                case 'D':
                    str_1 += "1101";
                    break;
                case 'E':
                    str_1 += "1110";
                    break;
                case 'F':
                    str_1 += "1111";
                    break;
                default:
                    break;
                }
            }
            // int len = 3 - str_1.length() % 3;
            // for (int i = 0; i < len; i++)
            //     str_1 = "0" + str_1;

            if (str_1.length() % 3 == 1)
                str_1 = "00" + str_1;
            else if (str_1.length() % 3 == 2)
                str_1 = "0" + str_1;
            int i = 0;
            for (int j = 0; j < str_1.length() - 1; j += 3)
            {
                a[i++] = (str_1[j] - '0') * 4 + (str_1[j + 1] - '0') * 2 + (str_1[j + 2] - '0') * 1;
            }
            for (int j = 0; j < i; j++)
            {
                if (a[j] == 0 && j == 0)
                    continue;
                else
                {
                    printf("%d", a[j]);
                }
            }
            printf("\n");
            // memset(str, 0, sizeof(str));
            // memset(a, 0, sizeof(a));
        }
    }
    return 0;
}
