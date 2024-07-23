#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isGoodArray(vector<int>& nums)
    {
        return ranges::fold_left(nums, 0, gcd<int, int>) == 1;
    }
};
