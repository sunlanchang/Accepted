#include <iostream>
#include <cstdio>
#include <cstring>
const int maxn = 2;
using namespace std;
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
    Mat m;
    m.mat[0][0] = m.mat[0][1] = m.mat[1][0] = 1;
    m.mat[1][1] = 0;
    m.col = m.row = 2;
    int n;
    while (~scanf("%d", &n) && n != -1)
    {
        Mat ans = mod_pow(m, n, 10000);
        printf("%d\n", ans.mat[0][1]);
    }
    return 0;
}