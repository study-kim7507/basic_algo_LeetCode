class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        vector<vector<int>> groups;
        sort(hand.begin(), hand.end());
        for (auto card : hand)
        {
            bool isFounded = false;
            for (auto& group : groups)
            {
                if (!group.empty() && group.back() == card - 1 && group.size() != groupSize)
                {
                    group.push_back(card);
                    isFounded = true;
                    break;
                }
            }

            if (!isFounded) 
            {
                vector<int> newGroup;
                newGroup.push_back(card);
                groups.push_back(newGroup);
            }
        }

        for (auto group : groups)
        {
            if (group.size() != groupSize) return false;
        }

        return true;
    }
};