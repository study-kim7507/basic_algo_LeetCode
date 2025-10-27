class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> devices;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < bank[i].size(); j++)
                if (bank[i][j] == '1') cnt++;
            if (cnt != 0)
                devices.push_back(cnt);
        }   

        int ans = 0;
        for (int i = 0; i < (int)(devices.size()) - 1; i++)
            ans += (devices[i] * devices[i + 1]);
        return ans;
    }
};