class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp;
        for (int i = 0; i < n; i++)
            dp.push_back(energy[i]);

        for (int i = k; i < n; i++)
            dp[i] = max(dp[i], dp[i] + dp[i - k]);
        
        int ans = -100000000;
        for (int i = n - k; i < n; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};