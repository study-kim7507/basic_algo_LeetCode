class Solution {
public:
    struct cmp
    {
        bool operator()(const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        }   
            
    };

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp());

        vector<int> ends(n, 0);
        for (int i = 0; i < n; i++)
            ends[i] = events[i][1];

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0];
            int val = events[i - 1][2];

            int prev = upper_bound(ends.begin(), ends.end(), start - 1) - ends.begin();

            for (int j = 1; j <= k; ++j) {
                dp[j][i] = max(
                    dp[j][i - 1],                     // 현재 이벤트 안 고름
                    dp[j - 1][prev] + val             // 현재 이벤트 고름
                );
            }
        }
        return dp[k][n];
    }
};