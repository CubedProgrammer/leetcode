#include<iostream>
#include<vector>
#include"sol.cpp"
using namespace std;
int main_pp(std::vector<std::string>&args)
{
    Solution sol;
    unsigned n, idiff, vdiff;
    cin >> n >> idiff >> vdiff;
    vector<int>nums(n);
    for(auto &x : nums)
        cin >> x;
    cout << boolalpha << sol.containsNearbyAlmostDuplicate(nums, idiff, vdiff) << endl;
    return 0;
}
int main(int argl,char**argv)
{
    std::vector<std::string>args(argv + 1, argv + argl);
    return main_pp(args);
}
