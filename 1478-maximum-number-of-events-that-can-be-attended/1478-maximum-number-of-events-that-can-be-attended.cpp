class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;        
        
        int n = events.size();
        int day = 1;
        int cnt = 0;
        int idx = 0;
        while (idx < n || !pq.empty())
        {
            while (idx < n && events[idx][0] <= day)
                pq.push(events[idx++][1]);
                
            while (!pq.empty() && pq.top() < day)
                pq.pop();   

            if (!pq.empty())
            {
                pq.pop();
                cnt++;
            }
            day++;
        }

        return cnt; 

    }
};