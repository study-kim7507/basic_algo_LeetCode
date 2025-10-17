class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<bool> rowIsZero(n, false);
        vector<bool> colIsZero(m, false);

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (matrix[r][c] == 0)
                {
                    rowIsZero[r] = true;
                    colIsZero[c] = true;
                }
            }
        }

        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (rowIsZero[r] || colIsZero[c])
                    matrix[r][c] = 0;
    }
};