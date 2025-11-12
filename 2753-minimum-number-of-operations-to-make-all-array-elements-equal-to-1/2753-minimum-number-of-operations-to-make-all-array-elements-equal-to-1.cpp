class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int oneCnt = 0;
        for (auto& num : nums)
            if (num == 1) oneCnt++;
        if (oneCnt != 0)
            return n - oneCnt;

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int gcd = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                gcd = __gcd(gcd, nums[j]);
                if (gcd == 1)
                {
                    ans = min(ans, j - i + n - 1);
                    break;
                }
            }
        }   

        return ans == INT_MAX ? -1 : ans;
    }
};