import sol;
std::function<int(std::vector<std::string>)>main_pp = [](std::vector<std::string>args)
{
    using namespace std;
    Solution solution;
    unsigned n;
    cin >> n;
    vector<int>arr;
    copy_n(istream_iterator<int>(cin), n, back_inserter(arr));
    std::println("{}", solution.canCross(arr));
    return 0;
};
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
