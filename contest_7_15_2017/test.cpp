#include <cstdio>
#include <queue>
#include <functional>
std::priority_queue<int, std::vector<__int64>, std::greater<int>> data;
int main()
{
    int n, i;
    __int64 temp, opt;
    scanf("%d", &n);
    for (i = opt = 0; i < n; ++i)
    {
        scanf("%I64d", &temp);
        data.push(temp);
    }
    if (n == 1)
        printf("%I64d", data.top());
    else
    {
        for (i = 1; i < n; ++i)
        {
            temp = data.top();
            data.pop();
            temp += data.top();
            data.pop();
            opt += temp;
            data.push(temp);
        }
        printf("%I64d", opt);
    }
    return 0;
}