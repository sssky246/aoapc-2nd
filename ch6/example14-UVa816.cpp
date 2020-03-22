#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

const std::string DIRE = "NESW";
const std::string TURN = "LFR";
const int MAXDIM = 10;
int maxr, maxc;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct WalkNode
{
    int r;
    int c;
    int dire;
    WalkNode(int _r = -1, int _c = -1, int _dire = -1)
        : r(_r), c(_c), dire(_dire) {}
};

bool MAZE[MAXDIM][MAXDIM][4][3];
int distance[MAXDIM][MAXDIM][4];
WalkNode path[MAXDIM][MAXDIM][4];

inline bool inside(const WalkNode &);
WalkNode walk(const WalkNode &u, char turn);
void buildMaze();
void solve(int startR, int startC, char startDire, int endR, int endC);
void print_answer(int startR, int startC, int dir, WalkNode endNode);

int main()
{
    while (true)
    {
        std::string name;
        std::cin >> name;
        if (name == "END")
            break;
        int startR, startC, endR, endC;
        char startDire;
        std::cin >> startR >> startC >> startDire >> endR >> endC;
        buildMaze();
        if (startR > maxr)
            maxr = startR;
        if (startC > maxc)
            maxc = startC;
        if (endR > maxr)
            maxr = endR;
        if (endC > maxc)
            maxc = endC;
        std::cout << name << std::endl;
        solve(startR, startC, startDire, endR, endC);
    }
    return 0;
}

inline bool inside(const WalkNode &u)
{
    return 1 <= u.r && u.r <= maxr && 1 <= u.c && u.c <= maxc;
}

WalkNode walk(const WalkNode &u, char turn)
{
    int dire = u.dire;
    if (turn == 'L')
        dire = (dire + 3) % 4;
    else if (turn == 'R')
        dire = (dire + 1) % 4;
    return WalkNode(u.r + dr[dire], u.c + dc[dire], dire);
}

void buildMaze()
{
    memset(MAZE, 0, sizeof(MAZE));
    maxr = 0;
    maxc = 0;
    while (true)
    {
        int r;
        std::cin >> r;
        if (r == 0)
            return;
        int c;
        std::cin >> c;
        std::string direction;
        while (std::cin >> direction && direction != "*")
        {
            std::stringstream ss(direction);
            char d;
            ss >> d;
            auto f = DIRE.find(d);
            while (ss >> d)
            {
                if (d == 'L')
                    MAZE[r][c][f][0] = 1;
                else if (d == 'F')
                    MAZE[r][c][f][1] = 1;
                else if (d == 'R')
                    MAZE[r][c][f][2] = 1;
            }
        }
        if (r > maxr)
            maxr = r;
        if (c > maxc)
            maxc = c;
    }
}

void solve(int startR, int startC, char startDire, int endR, int endC)
{
    memset(distance, -1, sizeof(distance));
    std::queue<WalkNode> q;
    auto i = DIRE.find(startDire);
    WalkNode startNode = WalkNode(startR + dr[i], startC + dc[i], i);
    distance[startNode.r][startNode.c][startNode.dire] = 0;
    q.push(startNode);
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        // go to the end node
        if (u.r == endR && u.c == endC)
        {
            print_answer(startR, startC, i, u);
            return;
        }
        for (std::size_t i = 0; i < 3; i++)
        {
            auto v = walk(u, TURN[i]);
            if (MAZE[u.r][u.c][u.dire][i] == 1 && inside(v) && distance[v.r][v.c][v.dire] < 0)
            {
                distance[v.r][v.c][v.dire] = distance[u.r][u.c][u.dire] + 1;
                path[v.r][v.c][v.dire] = u;
                q.push(v);
            }
        }
    }
    std::cout << "  No Solution Possible" << std::endl;
}

void print_answer(int startR, int startC, int dire, WalkNode endNode)
{
    std::vector<WalkNode> nodes;
    auto u = endNode;
    while (true)
    {
        nodes.push_back(u);
        if (distance[u.r][u.c][u.dire] == 0)
            break;
        u = path[u.r][u.c][u.dire];
    }
    nodes.push_back(WalkNode(startR, startC, dire));

    int cnt = 0;
    for (auto iter = nodes.crbegin(); iter != nodes.crend(); iter++)
    {
        if (cnt % 10 == 0)
            std::cout << " ";
        std::cout << " (" << iter->r << "," << iter->c << ")";
        cnt++;
        if (cnt % 10 == 0)
            std::cout << std::endl;
    }
    if (nodes.size() % 10 != 0)
        std::cout << std::endl;
}