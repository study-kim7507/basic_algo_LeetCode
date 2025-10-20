class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {        
        sort(trainers.begin(), trainers.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto player : players)
            pq.push(player);
            
        int n = trainers.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {   
            if (pq.empty()) break;
            if (pq.top() <= trainers[i])
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};