#include <iostream>
#include <vector>
#include <stack>

struct Matrix
{
    int m, n;
    Matrix(int _m = 0, int _n = 0) : m(_m), n(_n) {}
};

int main()
{
    int n;
    std::vector<Matrix> m;

    std::cin >> n;
    std::string strTmp;
    for (int i = 0; i < n; i++)
    {
        Matrix tmp;
        std::cin >> strTmp >> tmp.m >> tmp.n;
        m.push_back(tmp);
    }

    std::string line;
    while (std::cin >> line)
    {
        std::stack<Matrix> s;
        bool errorFlag = false;
        int sum = 0;
        int len = line.length();
        for (int i = 0; i < len; i++)
        {
            if (isalpha(line[i]))
                s.push(m[line[i] - 'A']);
            else if (line[i] == ')')
            {
                Matrix B = s.top();
                s.pop();
                Matrix A = s.top();
                s.pop();
                if (A.n != B.m)
                {
                    errorFlag = true;
                    break;
                }
                sum += A.m * A.n * B.n;
                s.push(Matrix(A.m, B.n));
            }
        }
        if (errorFlag)
            std::cout << "error" << std::endl;
        else
            std::cout << sum << std::endl;
    }

    return 0;
}