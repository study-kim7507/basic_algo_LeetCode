class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101];
        memset(dp, 0, sizeof(dp));

        for (auto& str : strs)
        {
            int c0 = 0, c1 = 0;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == '0') c0++;
                else if (str[i] == '1') c1++;
            }
            for (int i = m; i >= c0; i--)
            {
                for (int j = n; j >= c1; j--)
                    dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
            }
        }

        return dp[m][n];
    }
};