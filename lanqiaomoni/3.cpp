//answer 1799-07-16
#include <iostream>
#include <cstdio>
using namespace std;
bool run(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}
int main()
{
    int day = 8113;
    // int day = 5343;
    int cnt_year = 0;
    for (int i = 1778;; i++)
    {
        if (day <= 200)
            break;
        if (run(i))
            day -= 366;
        else
            day -= 365;
        cnt_year++;
    }
    cout << "year cnt: " << cnt_year << endl;
    cout << "day: " << day << endl;
    return 0;
}