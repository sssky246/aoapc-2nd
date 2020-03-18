#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <cctype>

struct Process
{
    int ID;
    int time;
    std::vector<std::string> code;
    std::size_t current_Line;

    Process(int id, int t, std::size_t cur = 0) : ID(id), time(t), current_Line(cur) {}
    Process() = default;
};

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        bool lock_Flag = false;
        int Var[26] = {0};
        int n, t1, t2, t3, t4, t5, Q;
        std::cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;

        std::deque<Process> ready_Deque;
        std::queue<Process> block_Queue;
        for (int i = 1; i <= n; i++)
        {
            Process p(i, Q);
            std::string line;
            while (std::getline(std::cin, line))
            {
                p.code.push_back(line);
                if (line == "end")
                    break;
            }
            ready_Deque.push_back(p);
        }

        while (!ready_Deque.empty())
        {
            Process p = ready_Deque.front();
            ready_Deque.pop_front();
            int t = 0;
            for (p.time = Q; p.time > 0; p.time -= t)
            {
                std::stringstream code(p.code[p.current_Line]);
                std::string word;
                code >> word;
                if (word == "print")
                {
                    code >> word;
                    if (isalpha(word[0]))
                    {

                        std::cout << p.ID << ": " << Var[word[0] - 'a'] << std::endl;
                        p.current_Line++;
                        t = t2;
                        continue;
                    }
                    else
                    {
                        std::cerr << "illegal variable name" << std::endl;
                        return 0;
                    }
                }
                else if (word == "lock")
                {
                    if (lock_Flag)
                    {
                        block_Queue.push(p);
                        break;
                    }
                    else
                    {
                        lock_Flag = true;
                        p.current_Line++;
                        t = t3;
                        continue;
                    }
                }
                else if (word == "unlock")
                {
                    lock_Flag = false;
                    p.current_Line++;
                    t = t4;
                    if (!block_Queue.empty())
                    {
                        ready_Deque.push_front(block_Queue.front());
                        block_Queue.pop();
                    }
                    continue;
                }
                else if (word == "end")
                {
                    p.current_Line++;
                    break;
                }
                else if (isalpha(word[0]))
                {
                    if (word.length() != 1)
                    {
                        std::cerr << "illegal variable name" << std::endl;
                        return 0;
                    }
                    else
                    {
                        char varName = word[0] - 'a';
                        code >> word;
                        if (word != "=")
                        {
                            std::cerr << "assignment error" << std::endl;
                        }
                        code >> Var[varName];
                        p.current_Line++;
                        t = t1;
                        continue;
                    }
                }
                else
                    p.current_Line++;
            }
            if (p.current_Line < p.code.size())
            {
                if (block_Queue.empty() || block_Queue.back().ID != p.ID)
                    ready_Deque.push_back(p);
            }
        }
        if (T != 0)
            std::cout << std::endl;
    }
    return 0;
}