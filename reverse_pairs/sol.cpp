#include <algorithm>
#include <limits>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    using Storage = unordered_map<unsigned, unsigned>;
    static constexpr unsigned BIG = numeric_limits<unsigned>::max();
    static constexpr unsigned DIFF = 0x80000000;
    void insert(Storage& dat, unsigned n)
    {
        for (++n; n != 0; n += n & -n)
            ++dat[n-1];
        ++dat[BIG];
    }
    unsigned query(const Storage& dat, unsigned n)
    {
        auto it = dat.find(n++);
        unsigned cnt = it == dat.end() ? 0 : it->second;
        for (n -= n & -n; n != 0; n -= n & -n)
        {
            it = dat.find(n - 1);
            cnt += it == dat.end() ? 0 : it->second;
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums)
    {
        if (nums.size() == 1)
            return 0;
        Storage tree;
        long first = nums.front();
        int tot = 0;
        // if only we could use enumerate, if only
        unsigned curr = 1;
        insert(tree, static_cast<unsigned>(first + DIFF));
        for (long i : nums | views::drop(1))
        {
            if (i < -0x40000000l)
                tot += curr;
            else if (i < 0x40000000l)
                tot += curr - query(tree, unsigned(i * 2 + DIFF));
            insert(tree, unsigned(i + DIFF));
            ++curr;
        }
        return tot;
    }
};
