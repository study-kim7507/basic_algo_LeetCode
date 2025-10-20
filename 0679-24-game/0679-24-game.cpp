class Solution {
public:
    bool ans = false;
    bool dfs(vector<double>& nums)
    {
        if (nums.size() == 1)
            return fabs(nums[0] - 24) < 1e-6;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j) continue;

                vector<double> nxt;

                // 이번 연산에 사용하려는 숫자 제거
                for (int k = 0; k < nums.size(); k++)
                    if (k != i && k != j) nxt.push_back(nums[k]);

                vector<double> candi;
                candi.push_back(nums[i] + nums[j]);
                candi.push_back(nums[i] - nums[j]);
                candi.push_back(nums[j] - nums[i]);
                candi.push_back(nums[i] * nums[j]);
                
                if (fabs(nums[i]) > 1e-6) candi.push_back(nums[i] / nums[j]);
                if (fabs(nums[j]) > 1e-6) candi.push_back(nums[j] / nums[i]);
                
                for (auto e : candi)
                {
                    nxt.push_back(e);
                    if (dfs(nxt)) return true;
                    nxt.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};