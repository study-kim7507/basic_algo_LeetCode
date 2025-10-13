class Solution {
public:
    bool isAnagram(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        
        int n = words.size();

        queue<string> q;
        for (auto word : words)
            q.push(word);
        
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            ans.push_back(cur);
            while (!q.empty())
            {
                auto nxt = q.front(); q.pop();
                if (!isAnagram(cur, nxt))
                {
                    cur = nxt;
                    ans.push_back(cur);
                }
            }
        }

        return ans;
    }
};