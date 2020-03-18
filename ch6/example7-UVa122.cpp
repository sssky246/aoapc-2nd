#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

struct Node
{
    Node *Left = nullptr;
    Node *Right = nullptr;
    int v;
    bool have_value = false;
};

int main()
{
    std::string s;

    while (std::cin >> s)
    {
        if (s == "()")
        {
            std::cout << "not complete" << std::endl;
            continue;
        }
        Node *root = new Node();
        bool failed = false;
        while (s != "()")
        {
            std::stringstream ss(s);
            char c;
            ss >> c;
            int v;
            ss >> v;
            while (ss >> c && c != ',')
                ;

            Node *u = root;
            while (ss >> c && c != ')')
            {
                if (c == 'L')
                {
                    if (u->Left == nullptr)
                        u->Left = new Node();
                    u = u->Left;
                }
                else if (c == 'R')
                {
                    if (u->Right == nullptr)
                        u->Right = new Node();
                    u = u->Right;
                }
            }
            if (u->have_value)
                failed = true;
            u->v = v;
            u->have_value = true;
            std::cin >> s;
        }

        std::queue<Node *> q;
        std::vector<int> ans;
        q.push(root);
        while (!q.empty())
        {
            Node *u = q.front();
            q.pop();
            if (!u->have_value)
                failed = true;
            ans.push_back(u->v);
            if (u->Left != nullptr)
                q.push(u->Left);
            if (u->Right != nullptr)
                q.push(u->Right);
        }

        if (failed)
            std::cout << "not complete" << std::endl;
        else
        {
            auto iter = ans.cbegin();
            while (iter != ans.cend() - 1)
            {
                std::cout << *iter << " ";
                ++iter;
            }
            std::cout << *iter << std::endl;
        }
    }
    return 0;
}