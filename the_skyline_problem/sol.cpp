#include <algorithm>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
public:
    using LineType = std::tuple<int, int, bool>;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<LineType>boundries;
        boundries.reserve(buildings.size() * 2);
        for (const auto& i : buildings)
        {
            boundries.emplace_back(i[0], -i[2], false);
            boundries.emplace_back(i[1], i[2], true);
        }
        ranges::sort(boundries);
        multiset<int>heights{0};
        vector<vector<int>>corners;
        for (auto [x, y, right] : boundries)
        {
            if (right)
            {
                heights.erase(heights.lower_bound(y));
                auto high = prev(heights.end());
                if (y > *high)
                    corners.push_back(vector<int>{x, *high});
            }
            else
            {
                y *= -1;
                if (heights.lower_bound(y) == heights.end())
                    corners.push_back(vector<int>{x, y});
                heights.insert(y);
            }
        }
        return corners;
    }
};
