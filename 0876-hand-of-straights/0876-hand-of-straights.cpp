class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        map<int, int> m;
        for (auto card : hand)
            m[card]++;
        
        while (!m.empty())
        {
            int cur = (*m.begin()).first;
            for (int i = cur; i <= cur + groupSize - 1; i++)
            {
                if (m.find(i) == m.end()) return false;
                if (--m[i] == 0) m.erase(i);
            }
        }

        return true;
    }
};