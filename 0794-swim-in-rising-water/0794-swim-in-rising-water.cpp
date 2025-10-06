#define X first
#define Y second

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = 0;

        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        visit[0][0] = true;
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            int curDist = cur.X;
            pair<int, int> curPos = cur.Y;

            ans = max(ans, curDist);
            if (curPos.X == n - 1 && curPos.Y == n - 1)
                break;

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = curPos.X + dx[dir];
                int ny = curPos.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visit[nx][ny]) continue;

                visit[nx][ny] = true;
                pq.push({grid[nx][ny], {nx, ny}});    
            }
        
        }
        return ans;        
    }
};