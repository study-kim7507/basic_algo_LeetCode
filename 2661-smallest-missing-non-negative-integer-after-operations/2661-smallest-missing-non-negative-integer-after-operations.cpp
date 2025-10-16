class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int ans = 0;

        vector<int> candi(value, 0);
        for (auto num : nums)
        {
            int q = abs(num) / value;
            int m = abs(num) % value;

            if (num > 0) candi[m]++;
            else
            {
                if (m == 0) candi[m]++;
                else candi[value - m]++;
            }
        }

        int minQ = *min_element(candi.begin(), candi.end());
        for (int i = 0; i < value; i++)
        {
            if (candi[i] - minQ == 0)
            {
                ans = value * minQ + i;
                break;
            }
        }

        return ans;
    }
};