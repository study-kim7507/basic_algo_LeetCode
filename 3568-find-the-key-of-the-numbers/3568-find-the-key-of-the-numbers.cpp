class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        vector<int> n1(4, 0);
        vector<int> n2(4, 0);
        vector<int> n3(4, 0);

        for (int i = 0; i < 4; i++)
        {
            n1[3 - i] = num1 % 10;
            num1 /= 10;
            n2[3 - i] = num2 % 10;
            num2 /= 10;
            n3[3 - i] = num3 % 10;
            num3 /= 10;
        }

        int ans = 0;
        for (int i = 0; i < 4; i++)
            ans += pow(10, 3 - i) * min({n1[i], n2[i], n3[i]});     
        return ans;
    }
};