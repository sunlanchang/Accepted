#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 25;

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

int n, m, mod = 1000;
int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m) && (m || n))
    {
        Mat ans1;
        ans1.col = ans1.row = n;
        memset(ans1.mat, 0, sizeof(ans1.mat));
        for (int i = 0; i < m; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            ans1.mat[s][t] = 1;
        }
        int T;
        scanf("%d", &T);
        for (int i = 0; i < T; i++)
        {
            int a, b, k;
            scanf("%d%d%d", &a, &b, &k);
            Mat ans2 = mod_pow(ans1, k, mod);
            printf("%d\n", (ans2.mat[a][b] % mod + mod) % mod);
        }
    }
    return 0;
}
