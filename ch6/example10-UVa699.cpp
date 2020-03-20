#include <iostream>
#include <map>

void build(int pos, std::map<int, int> &ans)
{
    int v;
    std::cin >> v;
    if (v == -1)
        return;
    if (ans.count(pos) == 0)
        ans[pos] = 0;
    ans[pos] += v;
    // build leftchild tree
    build(pos - 1, ans);
    // build rightchild tree
    build(pos + 1, ans);
}

int main()
{
    for (int kase = 1;; kase++)
    {
        std::map<int, int> ans;
        build(0, ans);
        if (ans.size() == 0)
            break;
        std::cout << "Case " << kase << ":" << std::endl;
        bool first = true;
        for (auto iter = ans.cbegin(); iter != ans.cend(); iter++)
        {
            if (!first)
            {
                std::cout << " ";
            }
            std::cout << iter->second;
            first = false;
        }
        std::cout << "\n"
                  << std::endl;
    }
    return 0;
}