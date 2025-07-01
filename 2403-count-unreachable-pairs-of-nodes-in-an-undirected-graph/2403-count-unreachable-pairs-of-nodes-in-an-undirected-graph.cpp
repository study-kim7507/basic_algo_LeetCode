class Solution {
public:
    long long countPairs(long long n, vector<vector<int>>& edges) {
        long long ans = n * (n - 1) / 2;

        vector<vector<int>> adjs(n, vector<int>());
        for (auto edge : edges)
        {
            int u, v;
            u = edge[0];
            v = edge[1];
            adjs[u].push_back(v);
            adjs[v].push_back(u);
        }

        vector<bool> vis(n, false);
         
        for (int i = 0; i < n; i++)
        {
            if (vis[i]) continue; 
               
            queue<int> q;
            q.push(i);
            vis[i] = true;

            long long cnt = 0;
            while (!q.empty())
            {
                auto cur = q.front(); q.pop();
                cnt++;
                for (auto nxt : adjs[cur])
                {
                    if (vis[nxt]) continue;
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }

            ans -= cnt * (cnt - 1) / 2;
        }

        return ans;
    }
};