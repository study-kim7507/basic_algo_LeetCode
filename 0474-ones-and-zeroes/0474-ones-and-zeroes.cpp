class Solution {
public:
    int dp[601][101][101];

    int solve(int i, int curZeroes, int curOnes, vector<pair<int, int>>& cost, int m, int n)
    {
        if (curZeroes > m || curOnes > n) return -1;
        if (i == cost.size()) return 0;

        if (dp[i][curZeroes][curOnes] != 0) return dp[i][curZeroes][curOnes];

        int take = 1 + solve(i + 1, curZeroes + cost[i].first, curOnes + cost[i].second, cost, m, n);
        int skip = solve(i + 1, curZeroes, curOnes, cost, m, n);

        return dp[i][curZeroes][curOnes] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> cost;
        for (auto& str : strs)
        {
            int zero = 0, one = 0;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == '0') zero++;
                else if (str[i] == '1') one++;
            }
            cost.push_back({zero, one});
        }

        return solve(0, 0, 0, cost, m, n);
    }
};