struct cmp
{
    bool operator() (const pair<int, long long>& a, const pair<int, long long>& b)
    {
        if (a.second > b.second) return true;
        else if (a.second == b.second) return a.first > b.first;
        return false;
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n, 0);
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> usedRooms;
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        for (int i = 0; i < n; i++)
            unusedRooms.push(i);

        // 시작 시간을 기준으로 오름차순 정렬
        sort(meetings.begin(), meetings.end());

        for (auto meeting : meetings)
        {
            int st = meeting[0];
            int en = meeting[1];

            while(!usedRooms.empty() && usedRooms.top().second <= st)
            {
                unusedRooms.push(usedRooms.top().first);
                usedRooms.pop();
            }

            if (!unusedRooms.empty())
            {
                int room = unusedRooms.top(); unusedRooms.pop();
                usedRooms.push({room, en});
                cnt[room]++;
            }
            else
            {
                auto room = usedRooms.top(); usedRooms.pop();
                usedRooms.push({room.first, room.second + en - st});
                cnt[room.first]++;
            }
        }

        int maxCnt = *max_element(cnt.begin(), cnt.end());
        for (int i = 0; i < n; i++)
            if (cnt[i] == maxCnt) return i;
        return 0;
    }
};