class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        int n = s1.size();
        unordered_map<char, char> um;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i]) continue;
            if (um.find(s1[i]) != um.end()) return false;
            um[s1[i]] = s2[i];
        }

        if (um.size() == 2)
        {
            auto it1 = um.begin();
            auto it2 = ++um.begin();

            if (it1->first == it2->second && it1->second == it2->first) return true;
        }
        
        return false;
    }
};