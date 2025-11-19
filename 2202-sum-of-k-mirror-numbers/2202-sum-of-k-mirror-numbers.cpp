class Solution {
public:
    long long createPalindrome(long long num, bool isOdd)
    {
        long long q = num;
        if (isOdd) q /= 10;
        while (q > 0)
        {
            num = num * 10 + q % 10;
            q /= 10;
        }

        return num;
    }

    bool isPalindrome(long long num, int base)
    {
        vector<int> digits;
        while (num > 0)
        {
            digits.push_back(num % base);
            num /= base;
        }

        int st = 0, en = digits.size() - 1;
        while (st < en)
        {
            if (digits[st] != digits[en]) return false;
            st++; en--;
        }

        return true;
    }

    long long kMirror(int k, int n) {
        long long ans = 0;
        for (long long i = 1; n > 0; i *= 10)
        {
            // 2 * d - 1
            for (long long cur = i; n > 0 && cur < i * 10; cur++)
            {
                long long p = createPalindrome(cur, true);
                if (isPalindrome(p, k)) 
                {
                    ans += p;
                    n--;
                }
            }
            // 2 * d
            for (long long cur = i; n > 0 && cur < i * 10; cur++)
            {
                long long p = createPalindrome(cur, false);
                if (isPalindrome(p, k)) 
                {
                    ans += p;
                    n--;
                }
            }
        }

        return ans;
    }
};