#include<format>
#include<functional>
#include<iostream>
#include<print>
#include<vector>
#include"sol.cpp"
std::function<int(std::vector<std::string>)>main_pp = [](std::vector<std::string>args)
{
    Solution sol;
    int n, k;
    cin >> n >> k;
    std::println("{}", sol.getPermutation(n, k));
    return 0;
};
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
