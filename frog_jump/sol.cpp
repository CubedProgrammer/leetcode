export module sol;
export import std;
using namespace std;
export
class Solution
{
public:
    bool canCross(vector<int>& stones)
    {
        map<int, unordered_set<int>>m;
        for(int i:stones | views::drop(1))
            m.insert({i, {}});
        auto& [one, s] = *m.begin();
        if(one != 1)
            return false;
        s.insert(1);
        while(m.size() > 1)
        {
            const auto &[v, s] = *m.begin();
            for(int i : s)
            {
                for(int j: views::iota(i - 1, i + 2))
                {
                    auto it = m.find(v + j);
                    if(it != m.end())
                    {
                        auto &ns = it->second;
                        ns.insert(j);
                    }
                }
            }
            m.erase(m.begin());
        }
        return!m.begin()->second.empty();
    }
};
