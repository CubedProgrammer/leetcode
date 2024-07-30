#include <functional>
#include <iostream>
#include <print>
#include <vector>
#include "sol.cpp"
std::function<int(std::vector<std::string>)>main_pp = [](std::vector<std::string>args)
{
    Solution solution;
    unsigned n;
    cin >> n;
    vector paths(n, vector(2, string{}));
    for (auto& i : paths)
        cin >> i[0] >> i[1];
    auto ans = solution.findItinerary(paths);
    for (const auto& i : ans)
        println("{}", i);
    return 0;
};
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
