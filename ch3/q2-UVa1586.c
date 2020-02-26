#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXN 100
#define C 0
#define H 1
#define O 2
#define N 3
#define TOTAL 4

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        char s[MAXN];
        scanf("%s", s);
        int n = strlen(s);
        // C H O N
        int count[4] = {0, 0, 0, 0};

        int molar;
        for (int i = 0; i < n;)
        {
            int counts = 1;
            switch (s[i])
            {
            case 'C':
                molar = C;
                break;
            case 'H':
                molar = H;
                break;
            case 'O':
                molar = O;
                break;
            case 'N':
                molar = N;
                break;
            default:
                break;
            }
            ++i;
            if (i < n && isdigit(s[i]))
            {
                counts = s[i] - '0';
                i++;
                while (i < n && isdigit(s[i]))
                {
                    counts = counts * 10 + s[i++] - '0';
                }
            }
            count[molar] += counts;
        }
        printf("%.3f\n", count[C] * 12.01 + count[H] * 1.008 + count[O] * 16.00 + count[N] * 14.01);
    }

    return 0;
}