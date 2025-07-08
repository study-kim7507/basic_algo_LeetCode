vector<int> edges[100001];
int ans = 0;

class Solution {
public:
    void dfs(int cur, int accTime, vector<int>& informTime)
    {
        if (edges[cur].empty())
        {
            ans = max(ans, accTime);
            return;
        }

        for (auto child : edges[cur])
            dfs(child, accTime + informTime[cur], informTime);
    }


    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {        
        fill (edges, edges + n + 1, vector<int>());
        for (int i = 0; i < n; i++)
        {
            if (manager[i] == -1) continue;
            edges[manager[i]].push_back(i);
        }

        ans = 0;
        dfs(headID, 0, informTime);

        return ans;
    }
};