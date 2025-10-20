class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int n = words.size();

        unordered_map<string, int> um1;       
        unordered_map<string, int> um2;

        for (auto word : words)
        {
            if (word[0] == word[1]) um2[word]++;
            else um1[word]++;
        }

        for (auto it = um1.begin(); it != um1.end(); it++)
        {
            string curString, curStringRev;
            curString = curStringRev = it->first;
            reverse(curStringRev.begin(), curStringRev.end());

            int m = min(um1[curString], um1[curStringRev]); 
            ans += (m * 2);
            um1[curString] -= m;
            um1[curStringRev] -= m;
        }

        for (auto it = um2.begin(); it != um2.end(); it++)
        {
            if (it->second != 1)
            {
                int m = it->second;
                if (m % 2 == 0) 
                {
                    ans += m;
                    it->second -= m;
                }
                else if (m % 2 == 1)
                {
                    ans += (m - 1);
                    it->second -= (m - 1);
                }
            }
        }
        
        for (auto it = um2.begin(); it != um2.end(); it++)
        {
            if (it->second != 0) 
            {
                ans++;
                break;
            }
        }
        
        return ans * 2;
    }
};