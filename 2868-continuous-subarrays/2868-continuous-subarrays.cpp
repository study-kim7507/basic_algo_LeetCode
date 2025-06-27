class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> window;
        int l = 0;
        long long answer = 0;

        for (int r = 0; r < nums.size(); ++r) {
            window.insert(nums[r]);

            // 조건이 안 맞으면 왼쪽을 줄여나감
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[l]));
                l++;
            }

            answer += (r - l + 1);
        }

        return answer;
    }
};
