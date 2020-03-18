#include <cstdio>
const int maxn = 100000 + 10;
int left[maxn];
int right[maxn];

void Link(int x, int y)
{
    right[x] = y;
    left[y] = x;
}

int main()
{
    int n, cmdNum;
    int kase = 1;
    while (scanf("%d%d", &n, &cmdNum) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1);
        }
        right[0] = 1;
        left[0] = n;

        int cmdCate;
        bool reverseFlag = false;
        while (cmdNum--)
        {
            scanf("%d", &cmdCate);
            if (cmdCate == 4)
                reverseFlag = !reverseFlag;
            else
            {
                int X, Y;
                scanf("%d%d", &X, &Y);
                int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
                if (reverseFlag && cmdCate != 3)
                    cmdCate = 3 - cmdCate;

                if (cmdCate == 1 && RX == Y)
                    continue;
                if (cmdCate == 2 && LX == Y)
                    continue;

                if (cmdCate == 1)
                {
                    Link(LX, RX);
                    Link(LY, X);
                    Link(X, Y);
                }
                else if (cmdCate == 2)
                {
                    Link(LX, RX);
                    Link(X, RY);
                    Link(Y, X);
                }
                else if (cmdCate == 3)
                {
                    if (RX == Y)
                    {
                        Link(LX, Y);
                        Link(Y, X);
                        Link(X, RY);
                    }
                    else if (LX == Y)
                    {
                        Link(LY, X);
                        Link(X, Y);
                        Link(Y, RX);
                    }
                    else
                    {
                        Link(LX, Y);
                        Link(Y, RX);
                        Link(LY, X);
                        Link(X, RY);
                    }
                }
            }
        }

        long long sum = 0;
        int val = 0;
        for (int i = 1; i <= n; i++)
        {
            val = right[val];
            if (i % 2 == 1)
            {
                sum += val;
            }
        }
        if (reverseFlag && n % 2 == 0)
        {
            sum = (long long)n * (n + 1) / 2 - sum;
        }
        printf("Case %d: %lld\n", kase++, sum);
    }
    return 0;
}