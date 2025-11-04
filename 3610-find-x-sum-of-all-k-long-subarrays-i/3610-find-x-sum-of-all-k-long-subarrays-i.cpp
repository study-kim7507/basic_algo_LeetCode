class Solution {
public:
    int calSum(const map<int, int>& m, const int& x)
    {
        priority_queue<pair<int, int>> pq;
        for(auto it = m.begin(); it != m.end(); it++)
            pq.push(make_pair(it->second, it->first));
        
        int sum = 0;
        for (int i = 0; i < x; i++)
        {
            if (pq.empty()) break;
            auto cur = pq.top(); pq.pop();
            sum += (cur.first * cur.second);
        }

        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        
        map<int, int> m;
        for (int i = 0; i < k; i++)
            m[nums[i]]++;
        ans.push_back(calSum(m, x));

        for (int i = 1; i < n - k + 1; i++)
        {
            m[nums[i - 1]]--;
            m[nums[i + k - 1]]++;
            ans.push_back(calSum(m, x));
        }
        return ans;
    }
};