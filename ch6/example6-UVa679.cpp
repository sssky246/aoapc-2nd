#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int D;
        long long I;
        scanf("%d%lld", &D, &I);
        long long k = 1;
        for (int i = 0; i < D - 1; i++)
        {
            if (I % 2)
            {
                k = k * 2;
                I = (I + 1) / 2;
            }
            else
            {
                k = k * 2 + 1;
                I = I / 2;
            }
        }
        printf("%lld\n", k);
    }
    return 0;
}