class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> rightUp(m + n - 1, vector<int>());
        vector<vector<int>> leftDown(m + n - 1, vector<int>());

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = i + j;
                if (sum % 2 == 0) rightUp[sum].push_back(mat[i][j]);
                else leftDown[sum].push_back(mat[i][j]);
            }
        }

        vector<int> merge;
        for (int i = 0; i <= m + n - 2; i++)
        {
            if (i % 2 == 0) 
            {
                reverse(rightUp[i].begin(), rightUp[i].end());
                for (auto e : rightUp[i])
                    merge.push_back(e);
            }
            else 
            {
                for (auto e : leftDown[i])
                    merge.push_back(e);
            }
        }
        return merge;
    }
};