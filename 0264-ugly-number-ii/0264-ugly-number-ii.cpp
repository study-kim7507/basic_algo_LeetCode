class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);

        long long res;
        for (int i = 0; i < n; i++)
        {
            res = *s.begin();
            s.erase(res);
            s.insert(res * 2);
            s.insert(res * 3);
            s.insert(res * 5);
        }

        return res;
    }
};