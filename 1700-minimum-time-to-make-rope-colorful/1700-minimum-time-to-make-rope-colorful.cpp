class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n =  neededTime.size();

        int ans = 0;

        int cur = 0;
        for (int i = 1; i < n; i++)
        {
            if (cur == i) continue;

            // 같은 색이라면
            if (colors[cur] == colors[i])
            {
                // 더 적은 시간이 걸리는 풍선(로프) 제거 
                ans += min(neededTime[cur], neededTime[i]);
                cur = neededTime[cur] >= neededTime[i] ? cur : i;
            }  
            else cur = i;
        }

        return ans;
    }
};