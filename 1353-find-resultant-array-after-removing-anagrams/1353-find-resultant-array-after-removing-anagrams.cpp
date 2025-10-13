class Solution {
public:
    bool isAnagram(string s1, string s2)
    {
        unordered_map<char, int> um_s1;
        unordered_map<char, int> um_s2;

        for (auto e : s1) um_s1[e]++;
        for (auto e : s2) um_s2[e]++;

        return um_s1 == um_s2;
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