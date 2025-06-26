class Solution {
public:
    int nthUglyNumber(int n, long long a, long long b, long long c) {
        long long l = 0;
        long long r = 2e9;

        int answer = 0;
        while (l <= r)
        {
            long long mid = (r + l) / 2;
            int cnt = 
            mid / a + mid / b + mid / c 
            - mid / (a * b / __gcd(a, b)) 
            - mid / (a * c / __gcd(a, c))
            - mid / (b * c / __gcd(b, c))
            + mid / lcm(a, lcm(b, c));
            if (cnt >= n)
            {
                answer = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return answer;
    }
};