class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        queue<int> window;

        for (int i = 0; i < n; i++)
        {   
            while(!window.empty() && abs(window.front() - nums[i]) > 1)
                window.pop();
            window.push(nums[i]);

            if (window.front() != window.back())
                ans = max(ans, (int)window.size());

            // std::cout << nums[i] << " " << ans << "\n";
        }
        return ans;
    }
};