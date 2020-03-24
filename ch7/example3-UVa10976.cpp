#include <iostream>
#include <vector>

int main()
{
    int k;
    while (std::cin >> k)
    {
        if (k == 0)
            return 0;
        std::vector<int> ans_x, ans_y;
        for (int y = k + 1; y <= 2 * k; y++)
        {
            double x = 1.0 * k * y / (y - k);
            if (static_cast<int>(x) == x)
            {
                ans_x.push_back(static_cast<int>(x));
                ans_y.push_back(y);
            }
        }
        std::cout << ans_x.size() << std::endl;
        for (int i = 0; i < ans_x.size(); i++)
        {
            std::cout << "1/" << k << " = 1/" << ans_x[i] << " + 1/" << ans_y[i] << std::endl;
        }
    }
    return 0;
}