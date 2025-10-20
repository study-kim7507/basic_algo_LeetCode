class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans = 0;

        int tLength = trainers.size();
        int pLength = players.size();

        int tIdx = 0;
        int pIdx = 0;

        for (tIdx = 0; tIdx < tLength; tIdx++)
        {
            if (pIdx == pLength) break;
            if (players[pIdx] <= trainers[tIdx])
            {
                ans++;
                pIdx++;
            }
        }

        return ans;
    }
};