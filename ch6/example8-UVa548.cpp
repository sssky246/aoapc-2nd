#include <iostream>
#include <sstream>
#include <cstring>

const int maxv = 10000 + 10;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n; // total number of vertex in the tree

// read vertex into the array
bool read_line(int *a)
{
    std::string line;
    if (!std::getline(std::cin, line))
        return false;
    std::stringstream ss(line);
    n = 0;
    int v;
    while (ss >> v)
        a[n++] = v;

    return (n > 0);
}

// build tree
int build(int L1, int R1, int L2, int R2)
{
    if (L1 > R1)
        return 0;
    int root = post_order[R2];
    int p = L1;
    while (in_order[p] != root)
        p++;
    int cnt = p - L1; // number of vertex in the leftchild tree
    lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
    rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
    return root;
}

void dfs(int v, int &sum, int &best, int &best_sum)
{
    sum += v;
    if (!lch[v] && !rch[v])
    {
        if (sum < best_sum || (sum == best_sum && v < best))
        {
            best_sum = sum;
            best = v;
        }
    }
    if (lch[v])
        dfs(lch[v], sum, best, best_sum);
    if (rch[v])
        dfs(rch[v], sum, best, best_sum);
}

int main()
{
    while (read_line(in_order))
    {
        read_line(post_order);
        std::memset(lch, 0, maxv);
        std::memset(rch, 0, maxv);
        build(0, n - 1, 0, n - 1);
        int sum = 0;
        int best_sum = 100000000;
        int best = 1000000000;
        dfs(post_order[n - 1], sum, best, best_sum);
        std::cout << best << std::endl;
    }
    return 0;
}