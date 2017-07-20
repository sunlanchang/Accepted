#include <iostream>

using namespace std;

int LINE, COL;
char mapOil[200][200];
bool visit[200][200];
int COUNT = 0;

void dfs(int i, int j)
{
    if (i < 0 || i >= LINE || j < 0 || j >= COL)
    {
        return;
    }
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if ((x != 0 || y != 0) && mapOil[i + x][j + y] == '@' && visit[i + x][j + y] == false)
            {
                visit[i + x][j + y] = true;
                dfs(i + x, j + y);
            }
        }
    }
}

void init()
{
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            mapOil[i][j] = '*';
            visit[i][j] = false;
        }
    }
    COUNT = 0;
}

int main()
{
    while (cin >> LINE >> COL && LINE && COL)
    {
        init();
        for (int i = 0; i < LINE; i++)
        {
            cin >> mapOil[i];
        }

        for (int i = 0; i < LINE; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (mapOil[i][j] == '@' && visit[i][j] == false)
                {
                    COUNT++;
                    visit[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        cout << COUNT << endl;
    }

    return 0;
}