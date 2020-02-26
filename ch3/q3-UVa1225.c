#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        int a[10];
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int number = i;
            while (number > 0)
            {
                a[number % 10]++;
                number /= 10;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[9]);
    }

    return 0;
}