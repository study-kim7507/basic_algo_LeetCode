class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        vector<long long> needs(n, 0); // 각각의 Potion이 Success를 넘기기 위해 필요한 최소 Spell값을 계산하여 보관
        for (int i = 0; i < n; i++)
        {
            long long q, r;
            q = success / potions[i];
            r = success % potions[i];

            if (q != 0 && r == 0) needs[i] = q;
            else if (q == 0 && r != 0) needs[i] = 1;
            else if (q != 0 && r != 0) needs[i] = q + 1; 
        }

        sort(needs.begin(), needs.end());

        vector<int> result;
        for (int spell : spells)
        {
            int count = upper_bound(needs.begin(), needs.end(), spell) - needs.begin();
            result.push_back(count);
        }

        return result;
    }
};