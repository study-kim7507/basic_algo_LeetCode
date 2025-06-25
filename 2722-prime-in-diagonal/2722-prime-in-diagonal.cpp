class Solution {
public:

    bool isPrime(int num)
    {
        if (num == 2) return true;   // Early Return
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) return false;
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        set<int> candi;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j || i + j == n - 1)
                {
                    if (nums[i][j] <= 1) continue;  // 1은 소수가 아님
                    if (nums[i][j] != 2 && nums[i][j] % 2 == 0) continue;   // 2를 제외한 짝수는 소수가 될 수 없음
                    candi.insert(nums[i][j]);
                }
            }
        }

        int answer = INT_MIN;
        for (auto e : candi)
        {
            if (isPrime(e)) 
                answer = max(answer, e);
        }
        return answer == INT_MIN ? 0 : answer;
    }
};