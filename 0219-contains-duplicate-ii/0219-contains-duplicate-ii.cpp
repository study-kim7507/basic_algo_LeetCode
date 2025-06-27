class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;
        
        unordered_set<int> windows;
        for (int i = 0; i < nums.size(); i++)
        {
            if (windows.find(nums[i]) != windows.end()) return true;

            if (i >= k)
                windows.erase(nums[i - k]);
            windows.insert(nums[i]); 
        }

        return false;
    }
};