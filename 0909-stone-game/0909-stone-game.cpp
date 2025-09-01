class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        // dp[i][j] : i ~ j 범위에서 현재 차례인 플레이어가 상대보다 더 얻을 수 있는 돌 차이
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // 초기값
        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        // 최초의 시작은 앨리스이므로 0 ~ n-1 까지의 값을 확인, 비교하여 반환
        return dp[0][n - 1] > 0;
    }
};