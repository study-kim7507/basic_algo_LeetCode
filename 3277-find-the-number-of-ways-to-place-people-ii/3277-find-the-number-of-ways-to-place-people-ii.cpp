#define X first
#define Y second

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] != b[0]) return a[0] > b[0];
        return a[1] < b[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        // 1. x값 기준 내림차순, y값이 기준 오름차순 정렬
        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            int y = INT_MAX, yi = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int yj = points[j][1];
                if (yj >= yi && y > yj)
                {
                    ans++;
                    y = yj;
                }
            }
        }
        return ans;
    }
};