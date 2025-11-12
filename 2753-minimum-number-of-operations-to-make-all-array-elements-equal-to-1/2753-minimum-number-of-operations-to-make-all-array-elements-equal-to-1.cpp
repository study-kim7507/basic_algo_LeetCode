class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int oneCnt = 0;

        // 1. 주어진 배열 내에 하나라도 1이 있으면, 해당 1이 퍼지면서 모든 수를 1로 만들 수 있음
        for (auto& num : nums)
            if (num == 1) oneCnt++;
        if (oneCnt != 0)
            return n - oneCnt;

        // 2. 그렇지 않다면 
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int gcd = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                gcd = __gcd(gcd, nums[j]);
                if (gcd == 1)
                {
                    ans = min(ans, j - i);
                    break;
                }
            }
        }   

        return ans == INT_MAX ? -1 : ans + n - 1;
    }
};