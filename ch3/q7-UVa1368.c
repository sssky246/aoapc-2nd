#include <stdio.h>
#include <string.h>

const char DNA[] = "ACGT";
#define A 0
#define C 1
#define G 2
#define T 3
int times[4];

#define MAXM 55
#define MAXN 1005
char a[MAXM][MAXN];
char result[MAXN];

int main()
{
    int counts;
    scanf("%d", &counts);
    while (counts--)
    {
        int m, n;
        int Ham_dis = 0;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++)
            scanf("%s", a[i]);

        for (int j = 0; j < n; j++)
        {
            memset(times, 0, sizeof(times));
            for (int i = 0; i < m; i++)
            {
                switch (a[i][j])
                {
                case 'A':
                    times[A]++;
                    break;
                case 'C':
                    times[C]++;
                    break;
                case 'G':
                    times[G]++;
                    break;
                case 'T':
                    times[T]++;
                    break;
                default:
                    break;
                }
            }
            int max = A;
            for (int i = 0; i < 4; i++)
            {
                if (times[i] > times[max])
                    max = i;
            }
            for (int i = 0; i < 4; i++)
                if (i != max)
                    Ham_dis += times[i];

            result[j] = DNA[max];
        }
        result[n] = '\0';
        printf("%s\n", result);
        printf("%d\n", Ham_dis);
    }

    return 0;
}