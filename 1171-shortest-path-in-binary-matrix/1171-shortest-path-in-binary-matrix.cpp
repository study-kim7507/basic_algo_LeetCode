#define X first
#define Y second

const int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1};

int dist[101][101];

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++)
            fill(dist[i], dist[i] + n + 1, 0);

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] != 0 || grid[nx][ny] != 0) continue;

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }

        if (dist[n - 1][n - 1] != 0)  
            return dist[n - 1][n - 1];
        return -1;
    }
};