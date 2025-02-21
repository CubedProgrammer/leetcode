export module sol;
export import std;
using namespace std;
export
class Solution
{
public:
    bool isValid(span<int>s) const noexcept
    {
        using views::enumerate;
        for(auto [i, u]: enumerate(s))
        {
            for(auto [j, v]: enumerate(s.subspan(0, i)))
            {
                if(u == v || abs(v - u) == abs(j - i))
                    return false;
            }
        }
        return true;
    }
    vector<string> build(span<int> s) const
    {
        using views::enumerate;
        vector board(s.size(), string(s.size(), '.'));
        for(auto [i, v]: enumerate(s))
            board[v][i] = 'Q';
        return board;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        if(n == 1)
            return{{"Q"}};
        if(n == 2 || n == 3)
            return{};
        if(n == 4)
            return{{"..Q.","Q...","...Q",".Q.."}, {".Q..","...Q","Q...","..Q."}};
        vector<int>arr(n);
        vector<vector<string>>positions;
        unsigned pos = 1;
        for(;;)
        {
            for(; arr[pos] < n && !isValid(arr | views::take(pos + 1)); ++arr[pos]);
            if(arr[pos] == n)
            {
                arr[pos] = 0;
                if(pos == 0)
                    break;
                else
                    ++arr[--pos];
            }
            else if(pos == n - 1)
            {
                positions.push_back(build(arr));
                ++arr[pos];
            }
            else
                ++pos;
        }
        return positions;
    }
};
