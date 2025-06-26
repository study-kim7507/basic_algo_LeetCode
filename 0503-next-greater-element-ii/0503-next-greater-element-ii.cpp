class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>> s;
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.top().first < nums[i])
            {
                res[s.top().second] = nums[i];
                s.pop();
            }
                
            s.push({nums[i], i});
        }

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.top().first < nums[i])
            {
                res[s.top().second] = nums[i];
                s.pop();
            }
        }

        return res;
    }
};