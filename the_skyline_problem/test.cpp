#include <functional>
#include <iostream>
#include <iterator>
#include <print>
#include <vector>
#include "sol.cpp"
std::function<int(std::vector<std::string>)>main_pp = [](std::vector<std::string>args)
{
    Solution solution;
    unsigned n;
    cin >> n;
    vector<vector<int>>buildings(n);
    for (auto &i : buildings)
        copy_n(istream_iterator<int>(cin), 3, back_inserter(i));
    vector<vector<int>>skyline = solution.getSkyline(buildings);
    for (const auto &i : skyline)
        println("{} {}", i[0], i[1]);
    return 0;
};
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
