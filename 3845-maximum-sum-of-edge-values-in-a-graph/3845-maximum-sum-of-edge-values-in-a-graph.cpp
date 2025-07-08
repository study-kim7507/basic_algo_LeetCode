class Solution {
public:


    long long maxScore(long long n, vector<vector<int>>& edges) {
        bool isCycle = edges.size() == n ? true : false;

        long long ans = 0;
        ans += n * (n - 1);
        ans += n * (n - 2);
        for (long long i = n - 1; i >= 1; i--)
            ans += i * max(i - 2, (long long)0);
        if (isCycle) ans += 2;
        
        return ans;
    }
};