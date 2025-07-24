class Solution {
    vector<int> subtreeXor;
    vector<int> in, out;
    int timer = 0;
    vector<vector<int>> tree;

    void dfs(int node, int parent, const vector<int>& nums) {
        in[node] = timer++;
        subtreeXor[node] = nums[node];
        for (int child : tree[node]) {
            if (child == parent) continue;
            dfs(child, node, nums);
            subtreeXor[node] ^= subtreeXor[child];
        }
        out[node] = timer++;
    }

    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        subtreeXor.assign(n, 0);
        in.assign(n, 0);
        out.assign(n, 0);
        timer = 0;

        dfs(0, -1, nums);
        int totalXor = subtreeXor[0];
        int ans = INT_MAX;

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            if (in[a] > in[b]) swap(a, b); // a is parent of b
            for (int j = i + 1; j < edges.size(); j++) {
                int c = edges[j][0], d = edges[j][1];
                if (in[c] > in[d]) swap(c, d); // c is parent of d

                int x, y, z;

                if (isAncestor(b, d)) {
                    // b ⊃ d: d 서브트리, (b - d)를 자르면 d 떨어짐
                    x = subtreeXor[d];
                    y = subtreeXor[b] ^ subtreeXor[d];
                    z = totalXor ^ subtreeXor[b];
                } else if (isAncestor(d, b)) {
                    // d ⊃ b
                    x = subtreeXor[b];
                    y = subtreeXor[d] ^ subtreeXor[b];
                    z = totalXor ^ subtreeXor[d];
                } else {
                    // 독립 서브트리
                    x = subtreeXor[b];
                    y = subtreeXor[d];
                    z = totalXor ^ x ^ y;
                }

                int mx = max({x, y, z});
                int mn = min({x, y, z});
                ans = min(ans, mx - mn);
            }
        }

        return ans;
    }
};
