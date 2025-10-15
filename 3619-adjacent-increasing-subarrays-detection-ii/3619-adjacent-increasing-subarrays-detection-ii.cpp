class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, prevInc = 0, maxLen = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i]) inc++;
            else
            {
                prevInc = inc;
                inc = 1;
            }
            maxLen = max({maxLen, inc / 2, min(prevInc, inc)});
        }

        return maxLen;
    }
};