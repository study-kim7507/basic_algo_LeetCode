class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> candi(value, 0);
        for (auto num : nums)
            candi[((num % value) + value) % value]++;

        int ans = 0;
        while (candi[ans % value]--) ans++;
        return ans;
    }
};