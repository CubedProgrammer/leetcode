#include <functional>
#include <iostream>
#include <print>
#include <vector>
#include "sol.cpp"
std::function<int(std::vector<std::string>)>main_pp = [](std::vector<std::string>args)
{
    Solution solution;
    unsigned n;
    int x, y;
    cin >> n;
    vector<vector<int>>points(n);
    for (auto &i : points)
    {
        cin >> x >> y;
        i.push_back(x);
        i.push_back(y);
    }
    std::println("{}", solution.maxPoints(points));
    return 0;
};
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
