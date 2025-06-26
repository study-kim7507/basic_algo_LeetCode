class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (s.empty() || (!s.empty() && s.top() <= nums[i]))
                s.push(nums[i]);
        }


        // while (!s.empty())
        // {
        //     std::cout << s.top() << " ";
        //     s.pop();
        // }
        return s.size();
    }
};