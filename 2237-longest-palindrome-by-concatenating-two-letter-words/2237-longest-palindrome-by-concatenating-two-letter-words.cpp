class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> um;
        for (string word : words)
            um[word]++;

        int ans = 0;
        bool isAlreadyPalindrome = false;
        for (auto [w, f] : um)
        {
            string r = w;
            reverse(r.begin(), r.end());

            if (w == r)
            {
                ans += (f / 2) * 4;
                if (f % 2 == 1) isAlreadyPalindrome = true;
            }
            else if (w < r && um.count(r)) ans += (min(f, um[r]) * 4);
        }

        if (isAlreadyPalindrome) ans += 2;
        return ans;
    }
};