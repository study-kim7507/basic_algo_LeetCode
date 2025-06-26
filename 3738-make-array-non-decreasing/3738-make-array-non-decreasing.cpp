class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> s;
        for (auto num : nums)
        {
            if (s.empty() || (!s.empty() && s.top() <= num))
                s.push(num);
        }

        return s.size();
    }
};