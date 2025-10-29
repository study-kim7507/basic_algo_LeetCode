class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int leftMaxDist = abs(fruits[0][0] - startPos);
        int rightMaxDist = abs(fruits[n - 1][0] - startPos);

        int startPosAmount = 0;
        
        // 시작 지점에서 특정 방향을 특정 거리만큼 이동 시 얻을 수 있는 과일의 개수
        vector<int> leftSum(leftMaxDist + 1, 0);
        vector<int> rightSum(rightMaxDist + 1, 0);
        for (auto fruit : fruits)
        {
            int pos = fruit[0];
            int amount = fruit[1];

            int dist = startPos - pos;
            if (dist == 0)
            {
                startPosAmount = amount;
                continue;
            }
            else if (dist > 0) leftSum[dist] = amount;
            else rightSum[abs(dist)] = amount; 
        }
        
        for (int i = 1; i <= leftMaxDist; i++)
            leftSum[i] += leftSum[i - 1];

        for (int i = 1; i <= rightMaxDist; i++)
            rightSum[i] += rightSum[i - 1];
     
            
        int ans = 0;
        for (int step = 1; step <= min(k, leftMaxDist); step++)
        {
            int tempAns = leftSum[step];
            int remainingStep = k - (2 * step);
            if (remainingStep > 0)
                tempAns += rightSum[min(remainingStep, rightMaxDist)];
        
            ans = max(ans, tempAns);
        }

        for (int step = 1; step <= min(k, rightMaxDist); step++)
        {
            int tempAns = rightSum[step];
            int remainingStep = k - (2 * step);
            if (remainingStep > 0)
                tempAns += leftSum[min(remainingStep, leftMaxDist)];
            
            ans = max(ans, tempAns);
        }
        ans += startPosAmount;

        return ans;
    }
};