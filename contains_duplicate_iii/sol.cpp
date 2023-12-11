#include<set>
#include<vector>
using namespace std;
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
    {
        set<int>s;
        int curr;
        s.insert(-2100000000);
        s.insert(2100000000);
        for(unsigned i = 0; i < nums.size(); ++i)
        {
            curr = nums[i];
            if(i > indexDiff)
                s.erase(nums[i - indexDiff - 1]);
            if(s.find(curr) == s.end())
            {
                auto it = s.insert(curr).first;
                auto before = it;
                auto after = it;
                --before;
                ++after;
                if(curr - valueDiff <= *before || *after <= curr + valueDiff)
                    return true;
            }
            else
                return true;
        }
        return false;
    }
};
