class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int leftMaxGap = 0;
        int rightMaxGap = 0;
        
        vector<bool> canRearrange(n, false);
        
        // leftMaxGap
        for (int i = 0; i < n; i++)
        {
            int duration = endTime[i] - startTime[i];
            if (duration <= leftMaxGap) canRearrange[i] = true;
            leftMaxGap = max(leftMaxGap, (i == 0 ? startTime[i] : startTime[i] - endTime[i - 1]));
        }

        // rightMaxGap
        for (int i = n - 1; i >= 0; i--)
        {
            int duration = endTime[i] - startTime[i];
            if (duration <= rightMaxGap) canRearrange[i] = true;
            rightMaxGap = max(rightMaxGap, (i == n - 1 ? eventTime - endTime[i] : startTime[i + 1] - endTime[i]));
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i == 0 ? 0 : endTime[i - 1];
            int right = i == n - 1 ? eventTime : startTime[i + 1];

            if (canRearrange[i]) ans = max(ans, right - left);
            else ans = max(ans, right - left - (endTime[i] - startTime[i]));
        }

        return ans;
    }
};