#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 0x7fffff;

bool exist(vector<int> v, int x)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (x == v[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int cas;
    while (scanf("%d", &cas) != EOF)
    {
        vector<int> x;
        vector<int> y;
        vector<int> ans_y;
        int cnt_cas = cas, y_line, x_line;
        while (cnt_cas--)
        {
            int x_tmp;
            int y_tmp;
            scanf("%d", &x_tmp);
            scanf("%d", &y_tmp);
            x.push_back(x_tmp);
            y.push_back(y_tmp);
        }
        vector<int> y_sort = y;
        vector<int> x_sort = x;
        sort(y_sort.begin(), y_sort.end());
        sort(x_sort.begin(), x_sort.end());
        if (y_sort.size() % 2 == 1)
        {
            int y_index = (y_sort.size() - 1) / 2;
            y_line = y_sort[y_index];
        }
        else
        {
            int y_index = y_sort.size() / 2;
            y_line = y_sort[y_index];
        }
        if (x_sort.size() % 2 == 1)
        {
            int x_index = (x_sort.size() - 1) / 2;
            x_line = x_sort[x_index];
        }
        else
        {
            int x_index = x_sort.size() / 2;
            x_line = x_sort[x_index];
        }
        for (int i = 0; i < x.size(); i++)
        {
            if (y[i] == y_line)
            {
                ans_y.push_back(y[i]);
                y[i] = INF;
                x[i] = INF;
            }
        }
        cout << "x line: " << x_line << "\n";
        cout << "y line: " << y_line << "\n";
        int sum_ele = cas;
        while (sum_ele--)
        {
            if (exist(ans_y, x_line) == true)
            {
                ans_y.push_back(x_line);
                x[x_line] = INF;
            }
            else
            {
                ;
            }
        }
        // for (int i = 0; i < y.size(); i++)
        // {
        //     // cout << y[i] << " ";
        //     cout << x[i] << " " << y[i] << "\n";
        // }
        // cout << "\nline: " << x_line << "\n";
    }
    return 0;
}