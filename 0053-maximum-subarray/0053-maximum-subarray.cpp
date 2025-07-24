class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCost = nums[0];
        int curCost = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            curCost = max(nums[i], curCost + nums[i]);
            maxCost = max(maxCost, curCost);
        }

        return maxCost;
    }
};