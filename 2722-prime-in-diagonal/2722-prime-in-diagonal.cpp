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
            int num1 = nums[i][i];
            int num2 = nums[i][n - 1 - i];

            if (num1 >= 2 && (num1 == 2 || (num1 != 2 && num1 % 2 != 0))) candi.insert(num1);
            if (num2 >= 2 && (num2 == 2 || (num2 != 2 && num2 % 2 != 0))) candi.insert(num2);
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