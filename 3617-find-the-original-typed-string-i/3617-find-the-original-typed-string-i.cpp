class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        string cur = "";
        for (int i = 0; i < word.size(); i++)
        {
            if (cur.empty() || cur.back() == word[i]) cur += word[i];
            else
            {
                ans += (cur.size() - 1);
                cur = "";
                cur += word[i];
            }
        }

        ans += (cur.size() - 1);
        return ans;
    }
};