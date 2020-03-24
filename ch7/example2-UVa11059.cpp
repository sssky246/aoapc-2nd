#include <iostream>
#include <vector>

int main()
{
    int n;
    int cnt = 1;
    while (std::cin >> n)
    {
        std::vector<int> numbers;
        for (int i = 0; i < n; i++)
        {
            int a;
            std::cin >> a;
            numbers.push_back(a);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long a = numbers[i];
            if (a > ans)
                ans = a;
            for (int j = i + 1; j < n; j++)
            {
                a *= numbers[j];
                if (a > ans)
                    ans = a;
            }
        }

        std::cout << "Case #" << cnt++ << ": The maximum product is " << ans << ".\n"
                  << std::endl;
    }
    return 0;
}