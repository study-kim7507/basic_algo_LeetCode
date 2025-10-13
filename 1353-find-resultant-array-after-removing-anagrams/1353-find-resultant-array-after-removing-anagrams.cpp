class Solution {
public:
    bool isAnagram(string s1, string s2)
    {
        unordered_map<char, int> um_s1;
        unordered_map<char, int> um_s2;

        for (auto e : s1)
            um_s1[e]++;
        for (auto e : s2)
            um_s2[e]++;

        for (auto it = um_s1.begin(); it != um_s1.end(); it++)
        {
            char curChar = it->first;
            int curCharCount = it->second;

            if (um_s2.find(curChar) == um_s2.end())
                return false;
            if (um_s2.find(curChar) != um_s2.end() && um_s2[curChar] != curCharCount)    
                return false;
            
            um_s2[curChar] = 0;
        }

        for (auto it = um_s2.begin(); it != um_s2.end(); it++)
            if (it->second != 0) return false;

        return true;
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