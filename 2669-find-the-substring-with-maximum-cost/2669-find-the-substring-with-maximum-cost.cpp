class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> values;
        for (char i = 'a'; i <= 'z'; i++)
            values[i] = i - 'a' + 1;
        for (int i = 0; i < vals.size(); i++)
            values[chars[i]] = vals[i];


        int maxCost = values[s[0]];
        int curCost = values[s[0]];
        for (int i = 1; i < s.size(); i++)
        {
            curCost = max(values[s[i]], curCost + values[s[i]]);
            maxCost = max(maxCost, curCost);
        }

        return max(0, maxCost);
    }
};