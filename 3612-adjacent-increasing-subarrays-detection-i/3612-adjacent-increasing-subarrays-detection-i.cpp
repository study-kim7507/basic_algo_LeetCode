class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; i++)
        {
            bool can = true;

            for (int j = i + 1; j < i + k; j++)
            {
                if (nums[j] <= nums[j - 1]) 
                {
                    can = false;
                    break;
                }
            }
            if (can)
            {
                for (int j = i + k + 1; j < i + 2 * k; j++)
                {
                    if (nums[j] <= nums[j - 1])
                    {
                        can = false;
                        break;
                    }
                }
            }

            if (can) return true;
        }

        return false;
    }
};