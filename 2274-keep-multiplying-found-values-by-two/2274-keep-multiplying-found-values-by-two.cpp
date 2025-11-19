class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> us;
        for (const int& num : nums)
            us.insert(num);

        int ans = original;
        while (true)
        {
            if (us.find(ans) == us.end()) break;
            ans *= 2;
        }
        
        return ans;
    }
};