class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int answer = 0;        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1 && (rows[i] >= 2 || cols[j] >= 2))
                    answer++;
            }
        }

        return answer;
    }
};