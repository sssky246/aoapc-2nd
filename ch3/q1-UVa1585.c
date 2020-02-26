#include <stdio.h>
#include <string.h>
#define MAXN 100

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char s[MAXN];
        scanf("%s", s);
        int score = 0;
        int sum = 0;
        int n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'O')
            {
                ++score;
                sum += score;
            }
            else
            {
                score = 0;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}