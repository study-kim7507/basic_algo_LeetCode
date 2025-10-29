class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = nums[i] + nums[j];
                int lb = lower_bound(nums.begin(), nums.end(), sum) - nums.begin();

                ans += max(0, (lb - (j + 1)));
            }
        }
        return ans;
    }
};