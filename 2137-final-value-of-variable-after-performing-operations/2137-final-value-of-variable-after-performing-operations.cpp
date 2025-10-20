class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto op : operations)
        {
            if (op == "++X" || op == "X++")
                ans++;
            else ans--;
        }

        return ans;
    }
};