#include <cstdio>
#include <cstring>

const int maxn = 100 + 10;
int m, n;
char pic[maxn][maxn];
int idx[maxn][maxn];

void dfs(int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;
    if (pic[r][c] != '@' || idx[r][c] == 1)
        return;
    idx[r][c] = 1;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i != 0 || j != 0)
                dfs(r + i, c + j);
        }
    }
}

int main()
{
    while (scanf("%d%d", &m, &n) && m && n)
    {
        memset(idx, 0, sizeof(idx));
        for (int i = 0; i < m; i++)
        {
            scanf("%s", pic[i]);
        }

        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pic[i][j] == '@' && idx[i][j] == 0)
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}