class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        vector<int> ans(n, 1);
        unordered_map<int, int> rainDay;        // 이전에 비온 날을 저장
        set<int> dry;                           // 이분탐색을 위해 

        for (int i = 0; i < n; i++)
        {
            if (rains[i] == 0)
                dry.insert(i);
            else
            {
                int rake = rains[i];
                if (rainDay.find(rake) != rainDay.end())
                {
                    int prev = rainDay[rake];
                    auto it = dry.lower_bound(prev);
                    if (it == dry.end()) return vector<int>();

                    ans[*it] = rake;
                    dry.erase(it);
                }
                rainDay[rake] = i;
                ans[i] = -1;
            }
        }

        return ans;
    }
};