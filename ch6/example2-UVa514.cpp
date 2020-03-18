#include <cstdio>
#include <stack>

const int maxn = 1000 + 10;

int main()
{
    bool nextBlock = false;
    bool first = true;
    int n;
    int target[maxn] = {0};
    while (true)
    {
        scanf("%d", &n);
        if (n == 0 && nextBlock == true)
        {
            break;
        }
        else if (n == 0 && nextBlock == false)
        {
            nextBlock = true;
            first = true;
            printf("\n");
            continue;
        }
        else
        {
            int i = 1;
            nextBlock = false;
            if (first)
            {
                target[0] = n;
                first = false;
            }
            else
            {
                target[i++] = n;
            }
            while (i <= target[0])
            {
                scanf("%d", &target[i++]);
            }
            int A = 1, B = 1;
            bool ok = true;
            std::stack<int> s;
            while (B <= target[0])
            {
                if (A == target[B])
                {
                    A++;
                    B++;
                }
                else if (!s.empty() && s.top() == target[B])
                {
                    B++;
                    s.pop();
                }
                else if (A <= target[0])
                {
                    s.push(A);
                    A++;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
    }

    return 0;
}