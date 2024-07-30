#include <algorithm>
#include <array>
#include <cmath>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;
namespace std
{
    template<>
    struct hash<array<int, 3>>
    {
        constexpr size_t operator()(const array<int, 3> &obj)const
        {
            auto[x, y, z] = obj;
            return x * 961 + y * 31 + z;
        }
    };
}
class Solution
{
public:
    int maxPoints(vector<vector<int>>& points)
    {
        using line = array<int, 3>;
        if (points.size() == 1)
            return 1;
        ranges::sort(points);
        unordered_map<line, unsigned>freq;
        int A, B, C;
        int divisor;
        for (size_t i = 0; i < points.size(); i++)
        {
            auto &u = points[i];
            for (size_t j = i + 1; j < points.size(); j++)
            {
                auto &v = points[j];
                B = v[0] - u[0];
                A = u[1] - v[1];
                divisor = gcd(B, abs(A));
                A /= divisor;
                B /= divisor;
                C = A * u[0] + B * u[1];
                ++freq[line{A, B, C}];
            }
        }
        return(static_cast<int>(sqrt(*ranges::max_element(freq | views::values) * 8 + 1)) + 1) >> 1;
    }
};
