class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        vector<long long> dp(n, 0);
        
        // 초기 값 설정
        dp[0] = mana[0] * skill[0];
        for (int i = 1; i < n; i++)
            dp[i] = dp[i - 1] + mana[0] * skill[i];
        
        for (int i = 1; i < m; i++)
        {
            // 시작 시간 찾기
            for (int j = n - 2; j >= 0; j--)
                dp[j] = max(dp[j], dp[j + 1] - (mana[i] * skill[j]));
            long long startTime = dp[0];

            // 시간 계산
            dp[0] += (mana[i] * skill[0]);
            for (int j = 1; j < n; j++)
                dp[j] = dp[j - 1] + (mana[i] * skill[j]);
        }

        return dp[n - 1];
    }
};