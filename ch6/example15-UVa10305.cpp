#include <iostream>
#include <cstring>
#include <vector>

const int maxn = 100 + 10;
int Graph[maxn][maxn];

int main()
{
    int n, m;
    while (std::cin >> n >> m && n)
    {
        memset(Graph, 0, sizeof(Graph));
        for (int i = 0; i < m; i++)
        {
            int r, c;
            std::cin >> c >> r;
            if (Graph[r][c] == 0)
            {
                Graph[r][c] = 1;
                Graph[r][0] += 1;
            }
        }
        std::vector<int> ans;
        while (true)
        {
            for (int i = 1; i <= n; i++)
            {
                if (Graph[i][0] == 0)
                {
                    ans.push_back(i);
                    Graph[i][0] = -1;
                    for (int j = 1; j <= n; j++)
                    {
                        if (Graph[j][i] == 1)
                        {
                            Graph[j][i] = 0;
                            Graph[j][0]--;
                        }
                    }
                }
            }
            if (ans.size() == n)
                break;
        }
        for (int i = 0; i < n - 1; i++)
        {
            std::cout << ans[i] << " ";
        }
        std::cout << ans[n - 1] << std::endl;
    }
    return 0;
}