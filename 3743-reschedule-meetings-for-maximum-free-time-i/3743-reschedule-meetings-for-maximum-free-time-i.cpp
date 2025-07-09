class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        // K개의 회의 조정 -> K + 1개의 연속된 자유시간의 최대 합.
        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for (int i = 1; i < n; i++)
            gaps.push_back(startTime[i] - endTime[i - 1]);
        gaps.push_back(eventTime - endTime[n - 1]);

        int ans = 0, sum = 0;
        for (int i = 0; i <= k; i++)
            sum += gaps[i];
        ans = max(ans, sum);

        for (int i = 1; i + k < gaps.size(); i++)
        {
            sum -= gaps[i - 1];
            sum += gaps[i + k];
            ans = max(ans, sum);
        }

        return ans;
    }
};