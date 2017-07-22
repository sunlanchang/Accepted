#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 100;

struct Mat
{
    int mat[maxn][maxn]; //矩阵
    int row, col;        //矩阵行列数
};
Mat mod_mul(Mat a, Mat b, int p) //矩阵乘法
{
    Mat ans;
    ans.row = a.row;
    ans.col = b.col;
    memset(ans.mat, 0, sizeof(ans.mat));
    for (int i = 0; i < ans.row; i++)
        for (int j = 0; j < ans.col; j++)
            for (int k = 0; k < a.col; k++)
            {
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                ans.mat[i][j] %= p;
            }
    return ans;
}
Mat mod_pow(Mat a, int k, int p) //矩阵快速幂
{
    Mat ans;
    ans.row = a.row;
    ans.col = a.col;
    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.col; j++)
            ans.mat[i][j] = (i == j);
    while (k)
    {
        if (k & 1)
            ans = mod_mul(ans, a, p);
        a = mod_mul(a, a, p);
        k >>= 1;
    }
    return ans;
}

int main()
{
    int n, k, m;
    while (~scanf("%d%d%d", &n, &k, &m))
    {
        Mat A;
        A.row = A.col = 2 * n;
        memset(A.mat, 0, sizeof(A));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &A.mat[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            A.mat[i][i + n] = A.mat[i + n][i + n] = 1;
        }
        Mat B = mod_pow(A, k + 1, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j < 2 * n; j++)
            {
                if (i + n == j)
                {
                    //(()+m)%m为了元素模完后是正数
                    printf("%d", ((B.mat[i][j] - 1) % m + m) % m);
                }
                else
                {
                    printf("%d", B.mat[i][j]);
                }
                printf("%c", j == 2 * n - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}