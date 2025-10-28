class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);

        for (int i = 1; i < n; i++)
            leftSum[i] += (leftSum[i - 1] + nums[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            rightSum[i] += (rightSum[i + 1] + nums[i + 1]);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0) continue;

            // 양쪽의 합이 모두 같은 경우, 어느 방향으로 시작해도 조건을 만족시킬 수 있음
            if (leftSum[i] == rightSum[i]) ans += 2;

            // 양쪽의 합의 차이가 1이 나는 경우, 더 합이 더 큰 방향으로 시작하면 조건을 만족시킬 수 있음
            else if (abs(leftSum[i] - rightSum[i]) == 1) ans += 1; 
        }

    
        return ans;
    }
};