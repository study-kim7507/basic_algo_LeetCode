#define X first
#define Y second

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int vis[101][101];

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {

        for (int i = 0; i < 101; i++)
            fill(vis[i], vis[i] + 101, 0x3f3f3f3f);

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            bool isFind = false;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    isFind = true;
                    queue<pair<int, int>> tempQ;
                    tempQ.push({i, j});
                    grid[i][j] = 2;

                    while(!tempQ.empty())
                    {
                        auto cur = tempQ.front(); tempQ.pop();
                        q.push(cur);
                        vis[cur.X][cur.Y] = 0;
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (grid[nx][ny] == 0 || grid[nx][ny] == 2) continue;

                            grid[nx][ny] = 2;
                            tempQ.push({nx, ny});
                        }
                    }
                }
                if (isFind) break;
            }
            if (isFind) break;
        }

        int answer = 0x3f3f3f3f;
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (grid[nx][ny] == 2) continue;
                if (vis[nx][ny] <= vis[cur.X][cur.Y] + 1) continue;
                if (grid[nx][ny] == 1) 
                {
                    answer = min(answer, vis[cur.X][cur.Y]);
                    continue;
                }

                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
       
        for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    std::cout << grid[i][j] << " ";
                std::cout << "\n";
            }
        return answer;
    }
};