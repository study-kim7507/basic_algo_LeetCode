class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());

        int ans = original;

        while (true)
        {
            auto lb = lower_bound(nums.begin(), nums.end(), ans);
            if (lb == nums.end()) break;
            if (lb != nums.end() && *lb != ans) break;

            ans *= 2;
        }

        return ans;
    }
};