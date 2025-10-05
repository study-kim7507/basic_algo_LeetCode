#define X first
#define Y second

class Solution {
public:
    const int dx[4] = { -1, 0, 1, 0 };
    const int dy[4] = { 0, -1, 0, 1 };

    int n, m;
    
    void bfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& canReachable)
    {
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        visit[i][j] = true;
        q.push({i, j});
        
        
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            canReachable[cur.X][cur.Y] = true;

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visit[nx][ny]) continue;
                if (heights[nx][ny] < heights[cur.X][cur.Y]) continue;

                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        vector<vector<bool>> canReachableToPacific(n, vector<bool>(m, false));
        vector<vector<bool>> canReachableToAtlantic(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) bfs(i, 0, heights, canReachableToPacific);
        for (int i = 0; i < m; i++) bfs(0, i, heights, canReachableToPacific);
        for (int i = 0; i < n; i++) bfs(i, m - 1, heights, canReachableToAtlantic);  
        for (int i = 0; i < m; i++) bfs(n - 1, i, heights, canReachableToAtlantic);  

        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (canReachableToPacific[i][j] && canReachableToAtlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};