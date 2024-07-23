#include <functional>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>
#include "sol.cpp"
namespace vi = std::views;
std::function<int(std::vector<std::string>)>main_pp = [](std::vector<std::string>args)
{
    Solution solution;
    unsigned n;
    cin >> n;
    vector<int> vec = vi::istream<int>(cin) | vi::take(n) | ranges::to<vector<int>>();
    std::println("{}", solution.isGoodArray(vec));
    return 0;
};
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
