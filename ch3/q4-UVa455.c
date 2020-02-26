#include <stdio.h>
#include <string.h>
#define STRMAX 100

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char s[STRMAX];
        scanf("%s", s);
        int length = strlen(s);
        int ans = 0;
        for (int i = 1; i <= length / 2; i++)
        {
            // find the first character which equals s[0]
            if (s[0] == s[i])
            {
                ans = i;
                if ((length % ans) != 0)
                {
                    ans = 0;
                    continue;
                }
                for (int j = ans; j < length; j++)
                {
                    if (s[j] != s[j % ans])
                    {
                        ans = 0;
                        break;
                    }
                }
                if (ans)
                    break;
            }
        }
        // if ans==0, print length of the string
        printf("%d\n", ans ? ans : length);
        if (T)
        {
            printf("\n");
        }
    }
    return 0;
}