class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;

        while (visit.find(n) == visit.end())
        {
            visit.insert(n);
            int currResult = 0;
            while (n > 0)
            {
                int digit = n % 10;
                currResult += digit * digit;
                n /= 10;
            }
            n = currResult;
            if (n == 1)
                return true;
        }

        return false;
    }
};