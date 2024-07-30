#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool findHelper(vector<string>&path, multiset<vector<string>> &edges)
    {
        if (edges.empty())
            return true;
        auto it = edges.lower_bound(vector{path.back()});
        bool found = false;
        while (!found && it != edges.end() && (*it)[0] == path.back())
        {
            auto flight = *it;
            path.push_back((*it)[1]);
            edges.erase(it);
            found = findHelper(path, edges);
            if (!found)
            {
                it = edges.insert(std::move(flight));
                path.pop_back();
                ++it;
            }
        }
        return found;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        vector<string>res{"JFK"};
        multiset ticketSet(tickets.begin(), tickets.end());
        findHelper(res, ticketSet);
        return res;
    }
};
