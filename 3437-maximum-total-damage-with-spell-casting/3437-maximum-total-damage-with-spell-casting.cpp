class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        
        int n = power.size();
        
        map<int, int> powerCount;
        for (int i = 0; i < power.size(); i++)
            powerCount[power[i]]++;
        
        vector<long long> dp(n);
        dp[0] = (long long)power[0] * powerCount[power[0]];
        for (int i = 1; i < n; i++)
        {
            long long take = (long long)power[i] * powerCount[power[i]];
            int prevIdx = upper_bound(power.begin(), power.begin() + i, power[i] - 3) - power.begin() - 1;
            if (prevIdx >= 0) take += dp[prevIdx];
            dp[i] = max(dp[i - 1], take);
        }

        return dp[n - 1];
    }
};