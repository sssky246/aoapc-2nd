#include <stdio.h>
#include <string.h>
#define MAXN 100

char a[MAXN][MAXN];
int row[MAXN];
int col[MAXN];

int eligible(int r, int c)
{
    // Black squares are not eligible
    if (a[r][c] == '*')
        return 0;
    // White squares with no squares either immediately to
    // the left or above are eligible
    if ((r - 1) < 0 || (c - 1) < 0)
        return 1;
    // White squares with black squares immediately to
    // the left or above are eligible
    if (a[r - 1][c] == '*' || a[r][c - 1] == '*')
        return 1;
    return 0;
}

int main()
{
    int puzzle = 0;
    while (1)
    {
        int counts = 0;
        int r, c;
        int i, j;
        scanf("%d", &r);
        if (r == 0)
            return 0;
        scanf("%d", &c);

        for (int i = 0; i < r; i++)
        {
            scanf("%s", a[i]);
        }

        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (eligible(i, j))
                {
                    row[counts] = i;
                    col[counts] = j;
                    counts++;
                }

        if (puzzle)
            printf("\n");
        printf("puzzle #%d:\n", ++puzzle);
        // Print across
        printf("Across\n");
        i = 0;
        j = 0;
        while (i < counts)
        {
            int m = row[i];
            int n = col[i];

            j = n;
            printf("%3d.", i + 1);
            while (j < c && a[m][j] != '*')
            {
                printf("%c", a[m][j]);
                j++;
            }
            if (j == c || n < j)
                while (i < counts && row[i] == m && col[i] < j)
                    i++;
            printf("\n");
        }

        // Print down
        printf("Down\n");
        i = 0;
        j = 0;
        while (i < counts)
        {
            int m = row[i];
            int n = col[i];
            if (a[m][n] == '*')
            {
                i++;
                continue;
            }
            j = m;

            printf("%3d.", i + 1);
            while (j < r && a[j][n] != '*')
            {
                printf("%c", a[j][n]);
                a[j][n] = '*';
                j++;
            }
            i++;
            printf("\n");
        }
    }
}