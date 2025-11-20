struct cmp
{
    bool operator()(const vector<int>& left, const vector<int>& right)
    {
        if (left[1] < right[1]) return left[1] < right[1];
        else if (left[1] == right[1]) return left[0] < right[0];
        return false;
    }
};

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // 끝 점을 기준으로 오름차순 정렬
        sort(intervals.begin(), intervals.end(), cmp());

        vector<int> chosen;
        chosen.push_back(intervals[0][1] - 1);
        chosen.push_back(intervals[0][1]);

        for (int i = 1; i < n; i++)
        {
            int curSt = intervals[i][0];
            int curEn = intervals[i][1];
            auto lb = lower_bound(chosen.begin(), chosen.end(), curSt);
            auto ub = upper_bound(chosen.begin(), chosen.end(), curEn);
            int cnt = int(ub - lb);

            if (cnt == 1)
            {
                int existing = *lb;
                if (existing == curEn) 
                {
                    chosen.pop_back();
                    chosen.push_back(curEn - 1);
                }
                chosen.push_back(curEn);
            }
            else if (cnt == 0)
            {
                chosen.push_back(curEn - 1);
                chosen.push_back(curEn);
            }
        }

        return (int)chosen.size();   
    }
};