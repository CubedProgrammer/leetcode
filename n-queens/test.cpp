import sol;
std::function<int(std::vector<std::string>)>main_pp = [](std::vector<std::string>args)
{
    using namespace std;
    Solution solution;
    int n;
    cin >> n;
    auto ans = solution.solveNQueens(n);
    for(const auto& i: ans)
    {
        for(const auto& j:i)
            println("{}", j);
        print("\n");
    }
    println("{}", ans.size());
    return 0;
};
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
