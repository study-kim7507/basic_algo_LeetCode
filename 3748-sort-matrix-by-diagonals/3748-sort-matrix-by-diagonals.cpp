class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> upper(n, vector<int>());
        vector<vector<int>> lower(n, vector<int>());

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (r < c) upper[c - r].push_back(grid[r][c]);
                else lower[r - c].push_back(grid[r][c]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            sort(upper[i].begin(), upper[i].end());
            sort(lower[i].rbegin(), lower[i].rend());
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));

        // 위쪽 삼각형 채우기
        for (int i = 1; i < n; i++)
        {
            pair<int, int> curPos = make_pair(0, i);
            for (auto e : upper[i])
            {
                ans[curPos.first][curPos.second] = e;
                curPos = make_pair(curPos.first + 1, curPos.second + 1);
            }
        }

        // 아래쪽 삼각형 채우기
        for (int i = 0; i < n; i++)
        {
            pair<int, int> curPos = make_pair(i, 0);
            for (auto e : lower[i])
            {
                ans[curPos.first][curPos.second] = e;
                curPos = make_pair(curPos.first + 1, curPos.second + 1);
            }
        }
        return ans;
    }
};