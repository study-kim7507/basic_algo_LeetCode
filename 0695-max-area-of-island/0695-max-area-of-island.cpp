#define X first
#define Y second

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

bool vis[51][51];

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
            fill (vis[i], vis[i] + m, false);


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] || grid[i][j] == 0) continue;

                int area = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                while(!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    area++;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny]) continue;
                        if (grid[nx][ny] == 0) continue;
  
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                ans = max(ans, area);
            }
        }

        return ans;
    }
};