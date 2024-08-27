#include <algorithm>
#include <numeric>
#include <span>
#include <vector>
using namespace std;
class Solution
{
public:
    constexpr int mergeSum(span<long>arr, span<long>buf, int lo, int up)
    {
        if (arr.size() == 1)
            return 0;
        size_t mid = arr.size() / 2;
        span left = arr.subspan(0, mid), right = arr.subspan(mid);
        int cnt = mergeSum(left, buf.subspan(0, mid), lo, up) + mergeSum(right, buf.subspan(mid), lo, up);
        for (long i : right)
            cnt += ranges::upper_bound(left, i - lo) - ranges::lower_bound(left, i - up);
        ranges::merge(left, right, buf.begin());
        ranges::copy(buf, arr.begin());
        return cnt;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        vector<long>summed, buffer(nums.size() + 1);
        summed.reserve(nums.size() + 1);
        summed.push_back(0);
        // using partial_sum would overflow
        for (long i : nums)
            summed.push_back(i + summed.back());
        return mergeSum(summed, buffer, lower, upper);
    }
};
