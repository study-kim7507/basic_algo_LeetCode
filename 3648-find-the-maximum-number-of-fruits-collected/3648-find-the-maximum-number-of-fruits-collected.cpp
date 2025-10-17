#define X first
#define Y second

class Solution {
public:
    int solve0(vector<vector<int>>& fruits)
    {
        int n = fruits.size();
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            ret += fruits[i][i];
            fruits[i][i] = 0;
        }

        return ret;
    }

    int solve1(vector<vector<int>>& fruits)
    {
        int dx[3] = {1, 1, 1};
        int dy[3] = {-1, 0, 1};

        int n = fruits.size();
        pair<int, int> startPos = make_pair(0, n - 1);

        vector<vector<int>> dp(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        dp[startPos.X][startPos.Y] = fruits[startPos.X][startPos.Y];
        q.push(startPos);

        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 3; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (nx >= ny) continue;
                if (dp[nx][ny] != -1 && dp[nx][ny] >= dp[cur.X][cur.Y] + fruits[nx][ny]) continue;
                
                dp[nx][ny] = dp[cur.X][cur.Y] + fruits[nx][ny];
                q.push({nx, ny});
            }
        }

        return dp[n - 2][n - 1];
    }

    int solve2(vector<vector<int>>& fruits)
    {
        int dx[3] = {-1, 0, 1};
        int dy[3] = {1, 1, 1};

        int n = fruits.size();
        pair<int, int> startPos = make_pair(n - 1, 0);

        vector<vector<int>> dp(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        dp[startPos.X][startPos.Y] = fruits[startPos.X][startPos.Y];
        q.push(startPos);

        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 3; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (nx <= ny) continue;
                if (dp[nx][ny] != -1 && dp[nx][ny] >= dp[cur.X][cur.Y] + fruits[nx][ny]) continue;
                
                dp[nx][ny] = dp[cur.X][cur.Y] + fruits[nx][ny];
                q.push({nx, ny});
            }
        }

        return dp[n - 1][n - 2];
    }

    
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int ans = solve0(fruits);
        ans += solve1(fruits);
        ans += solve2(fruits);
        return ans;
    }
};