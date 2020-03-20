#include <iostream>

int build()
{
    int wl, dl, wr, dr;
    std::cin >> wl >> dl >> wr >> dr;
    if (wl == 0)
    {
        wl = build();
    }
    if (wr == 0)
    {
        wr = build();
    }
    if ((wl * dl) != (wr * dr))
    {
        return -1;
    }
    else
    {
        return wl + wr;
    }
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        if (build() == -1)
        {
            std::cout << "NO" << std::endl;
        }
        else
        {
            std::cout << "YES" << std::endl;
        }
        if (T != 0)
            std::cout << std::endl;
    }
    return 0;
}