class Solution {
public:
    string solve(string s)
    {
        vector<char> v;
        for (auto e : s)
        {
            if (e == '#')
            {
                if (v.empty()) continue;
                v.pop_back();
            }
            else v.push_back(e);
        }

        string res;
        for (auto e : v)
            res += e;
        return res;
    }

    bool backspaceCompare(string s, string t) {
        return solve(s) == solve(t);
    }
};