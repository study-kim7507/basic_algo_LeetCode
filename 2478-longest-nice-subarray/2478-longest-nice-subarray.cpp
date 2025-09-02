class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxLen = 0;
        int start = 0;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            while ((curr & nums[i]) != 0)
            {
                curr ^= nums[start];
                start++;
            }

            curr |= nums[i];
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};