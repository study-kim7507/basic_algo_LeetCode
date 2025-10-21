class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        map<int, int> freq;
        for (auto num : nums)
            freq[num]++;

        int minValue = freq.begin()->first;
        int maxValue = prev(freq.end())->first;

        int ans = 0;
        for (int num = minValue; num <= maxValue; num++)
        {
            auto lb = lower_bound(nums.begin(), nums.end(), num - k);
            auto ub = upper_bound(nums.begin(), nums.end(), num + k);

            int count = --ub - lb + 1 - freq[num];
            if (count <= 0) ans = max(ans, freq[num]);
            else if (count <= numOperations) ans = max(ans, count + freq[num]);
            else if (count > numOperations) ans = max(ans, numOperations + freq[num]); 
        }

        return ans;
    }
};