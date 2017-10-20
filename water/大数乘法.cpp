#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int a[1111111], b[1111111], temp[1111111], la, lb;
void multi()
{
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < la; i++)
    {
        for (int j = 0; j < lb; j++)
        {
            //temp为保存一次相乘一次的中间结果
            temp[i + j] += a[i] * b[j];
            if (temp[i + j] > 9)
            {
                temp[i + j + 1] += temp[i + j] / 10;
                temp[i + j] %= 10;
            }
        }
        // for (int ii = 0; ii < la + lb; ii++)
        // {
        //     cout << temp[ii] << ' ';
        // }
        // cout << endl;
    }
    if (temp[la + lb - 2] > 9) //进位
    {
        temp[la + lb - 1] += temp[la + lb - 2] / 10;
        temp[la + lb - 2] %= 10;
        // cout << "进位" << endl;
    }
    la = la + lb;
    for (int i = 0; i < la; i++)
        a[i] = temp[i];
    // for (int i = 0; i < 20; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // cout << la << endl;
}
int main()
{
    char s[10];
    int n;
    while (~scanf("%s%d", s, &n))
    {
        int pos = -1; //小数点位置
        //将小数点去掉后的数字 ‘倒序’ 保存在a[]中，a[]为保存每一次相乘的结果，b[]为被乘数
        for (int i = 5, j = 0; i >= 0; i--)
            if (s[i] != '.')
                a[j] = s[i] - '0', b[j] = a[j], j++;
            else
                pos = i;
        //当有小数点时，la初始化为5（la后续会随着一次一次的相乘变大），被乘数lb是固定的
        la = lb = (pos == -1 ? 6 : 5);
        for (int i = 1; i < n; i++)
            multi();
        if (pos == -1) //没有小数点直接输出结果即可
        {
            for (int i = la - 1; i >= 0; i--)
                printf("%d", a[i]);
            printf("\n");
        }
        else //有小数点
        {
            int l, r;
            pos = 5 - pos;
            //结果中小数点位置，小数点原来位置是pos，那么结果小数点的位置应为pos*n
            pos *= n;                    //结果中小数点位置
            for (int i = 0; i < la; i++) //后置零
                if (a[i] != 0)
                {
                    l = i;
                    break;
                }
            for (int i = la - 1; i >= 0; i--) //前置零
                if (a[i] != 0)
                {
                    r = i;
                    break;
                }
            if (r < pos)
                r = pos - 1;
            if (l > pos)
                l = pos;
            for (int i = r; i >= l; i--)
            {
                if (i == pos - 1)
                    printf(".");
                printf("%d", a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}