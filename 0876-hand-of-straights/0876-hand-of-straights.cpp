class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        list<int> l(hand.begin(), hand.end());
        vector<int> v;

        for (int i = 0; i < hand.size(); i++)
        {
            for (auto it = l.begin(); it != l.end(); it++)
            {
                if (v.empty())
                {
                    v.push_back(*it);
                    l.erase(it);
                    if (v.size() == groupSize) v.clear();
                    break;
                }
                else
                {
                    if (v.back() == *it - 1)
                    {
                        v.push_back(*it);
                        l.erase(it);
                        if (v.size() == groupSize) v.clear();
                        break;
                    }
                }
            }
        }
        
        if (v.empty() && l.empty()) return true;
        else return false;
    }
};