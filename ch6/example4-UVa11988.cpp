#include <iostream>
#include <list>

int main()
{
    std::string text;
    while (std::cin >> text)
    {
        std::list<char> l;
        auto len = text.length();
        auto iter = l.end();
        for (std::size_t i = 0; i < len; i++)
        {
            if (text[i] == '[')
            {
                iter = l.begin();
            }
            else if (text[i] == ']')
            {
                iter = l.end();
            }
            else
            {
                l.insert(iter, text[i]);
            }
        }
        for (const char &c : l)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    return 0;
}