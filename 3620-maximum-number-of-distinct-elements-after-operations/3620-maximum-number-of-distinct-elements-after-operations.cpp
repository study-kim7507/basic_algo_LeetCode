class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        nums[0] -= k;

        for (int i = 1; i < n; i++)
        {
            int prev = nums[i - 1];
            int cur = prev + 1;

            nums[i] = max(nums[i] - k, min(cur, nums[i] + k));
        }

        int ans = 1;
        int prev = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (prev != nums[i]) 
            {
                ans++;
                prev = nums[i];
            }
        }

        return ans;
    }
};