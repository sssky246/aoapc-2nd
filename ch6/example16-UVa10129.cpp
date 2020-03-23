#include <iostream>
#include <cstring>
#include <set>

const int MAXN = 26 + 5;
int Graph[MAXN][MAXN];
std::set<char> nodeSet;

void buildGraph(int n)
{
    memset(Graph, 0, sizeof(Graph));
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        Graph[s[0] - 'a' + 1][s[s.size() - 1] - 'a' + 1]++;
        Graph[s[0] - 'a' + 1][0]++;
        Graph[0][s[s.size() - 1] - 'a' + 1]++;
        nodeSet.insert(s[0]);
        nodeSet.insert(s[s.size() - 1]);
    }
}

void isConnect(int node)
{
    if (nodeSet.count(node - 1 + 'a'))
        nodeSet.erase(node - 1 + 'a');
    else
        return;
    for (int i = 1; i <= 26; i++)
    {
        if (i != node && (Graph[node][i] != 0 || Graph[i][node] != 0))
        {
            isConnect(i);
        }
    }
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int n;
        std::cin >> n;
        nodeSet = std::set<char>();
        buildGraph(n);
        for (int i = 1; i <= 26; i++)
        {
            if (Graph[0][i] != 0)
            {
                isConnect(i);
                break;
            }
        }
        if (!nodeSet.empty())
        {
            std::cout << "The door cannot be opened." << std::endl;
            continue;
        }
        int x = 0, y = 0;
        bool badFlag = false;
        for (int i = 1; i <= 26; i++)
        {
            if (Graph[i][0] != Graph[0][i])
            {
                if (Graph[i][0] == Graph[0][i] + 1)
                    x++;
                else if (Graph[i][0] + 1 == Graph[0][i])
                    y++;
                else
                {
                    badFlag = true;
                    break;
                }
            }
        }
        if (badFlag == false && (x == y) && (x == 0 || x == 1))
            std::cout << "Ordering is possible." << std::endl;
        else
            std::cout << "The door cannot be opened." << std::endl;
    }
    return 0;
}