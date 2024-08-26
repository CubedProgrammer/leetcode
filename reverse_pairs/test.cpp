#include <functional>
#include <iostream>
#include <iterator>
#include <print>
#include "sol.cpp"
std::function<int(std::vector<std::string>)>main_pp = [](std::vector<std::string>args)
{
    Solution solution;
    unsigned n;
    cin >> n;
    vector<int>arr;
    arr.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(arr));
    println("{}", solution.reversePairs(arr));
    return 0;
};
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
