class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int cur = n  + 1; cur <= 6666661; cur++)
        {
            vector<int> cnt(10, 0);

            int temp = cur;
            while (temp != 0)
            {
                cnt[temp % 10]++;
                temp /= 10;
            }

            bool can = true;
            for (int i = 0; i < 10; i++)
            {
                if (cnt[i] != 0 && cnt[i] != i)
                {
                    can = false;
                    break;
                }
            }

            if (can == true)
                return cur;
        }

        return 0;
    }
};