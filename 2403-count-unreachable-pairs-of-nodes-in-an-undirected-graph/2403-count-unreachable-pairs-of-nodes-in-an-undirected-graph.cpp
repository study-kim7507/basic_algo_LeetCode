int parent[100001];
int cnt[100001];

class Solution {
public:

    int find(int x)
    {
        if (x != parent[x]) return parent[x] = find(parent[x]);
        return x;
    }

    void uf_union(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (x < y) 
        {
            parent[y] = x;
            cnt[x] += cnt[y];
        }
        else 
        {
            parent[x] = y;
            cnt[y] += cnt[x];
        }
    }

    long long countPairs(long long n, vector<vector<int>>& edges) {
        long long ans = (long long)(n * (n - 1) / 2);
        
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            cnt[i] = 1;
        }
            

        for (auto edge : edges)
        {
            int u, v;
            u = edge[0];
            v = edge[1];

            if (find(u) != find(v))
                uf_union(u, v);
        }    
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                long long size = (long long)cnt[i];
                ans -= size * (size - 1) / 2;
            } 
        }
            
        
        return ans;
    }
};