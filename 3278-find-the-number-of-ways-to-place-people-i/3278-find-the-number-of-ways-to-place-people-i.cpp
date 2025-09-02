#define X first
#define Y second

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        // 1. x값이 작고, y값이 큰 것을 기준으로 내림차순 정렬
        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // 2. 정점 쌍 조건 -> A.x <= B.x && A.y >= B.y
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1])
                {
                    bool isCan = true;
                    // 3. 정점 쌍이 이루는 사각형 내부에 다른 정점이 위치해있는지 여부 판단
                    for (int k = 0; k < n; k++)
                    {
                        if (k == i || k == j) continue;

                        pair<int, int> a = make_pair(points[i][0], points[i][1]);
                        pair<int, int> b = make_pair(points[j][0], points[j][1]);
                        pair<int, int> current = make_pair(points[k][0], points[k][1]);
                        
                        if ((current.X >= a.X && current.X <= b.X) && 
                            (current.Y >= b.Y && current.Y <= a.Y))
                            isCan = false;

                        if (!isCan) break;
                    }   
                    if (isCan) ans++;                 
                }
            }
        }
        return ans;
    }
};