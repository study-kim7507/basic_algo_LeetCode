class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l = 0;
        int zero = 0, one = 0;

        int answer = 0;
        for (int r = 0; r < s.size(); r++)
        {
            if (s[r] == '0') zero++;
            else one++;

            while (l < r && zero > k && one > k)
            {
                if (s[l] == '0') zero--;
                else one--;

                l++;
            }

            answer += (r - l) + 1;
        }

        return answer;
    }
};