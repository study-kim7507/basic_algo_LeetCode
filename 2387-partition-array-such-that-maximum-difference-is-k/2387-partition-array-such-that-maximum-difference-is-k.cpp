class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        int left = 0;
        int right = 0;
        while (right < n)
        {
            if (nums[right] > nums[left] + k)
            {
                left = right;
                ans++;
            }
            right++; 
        }
        ans++;
        return ans;
    }
};