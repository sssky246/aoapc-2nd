#include <iostream>
#include <set>

bool right(int n, std::set<int> &digits)
{
    for (int i = 0; i < 5; i++)
    {
        int x = n % 10;
        if (digits.count(x))
            return false;
        digits.insert(x);
        n /= 10;
    }
    return true;
}

int main()
{
    int n;
    bool first = true;
    while (std::cin >> n && n)
    {
        if (first)
            first = false;
        else
            std::cout << std::endl;

        std::set<int> ans;
        for (int i = 1000; i <= 98765; i++)
        {
            int abcde = i * n;
            if (abcde >= 100000)
                break;
            std::set<int> digits;
            if (right(i, digits))
            {
                if (right(abcde, digits))
                    ans.insert(i);
            }
        }
        if (ans.empty())
            std::cout << "There are no solutions for " << n << "." << std::endl;
        else
        {
            for (auto it : ans)
            {
                std::cout << it * n << " / ";
                if (it < 10000)
                    std::cout << "0";
                std::cout << it << " = " << n << std::endl;
            }
        }
    }
    return 0;
}