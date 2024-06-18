#include<algorithm>
#include<ranges>
#include<string>
using namespace std;
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        auto startrange = views::iota('1', '1' + n) | views::common;
        string s(begin(startrange), end(startrange));
        // naive solution will work, n is at most nine
        // no need for order statistic tree
        for(--k; k > 0; --k)
            ranges::next_permutation(s);
        return s;
    }
};
