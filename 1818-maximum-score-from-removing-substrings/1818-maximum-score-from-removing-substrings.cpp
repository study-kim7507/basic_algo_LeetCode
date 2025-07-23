class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string target = x <= y ? "ba" : "ab";
        stack<char> st;

        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string cur = "";
            if (!st.empty()) cur += st.top();
            cur += s[i];

            if (cur == target)
            {
                ans += x <= y ? y : x;
                st.pop();
            } 
            else st.push(s[i]);
        }
        
        string remain = "";
        while (!st.empty())
        {
            remain += st.top();
            st.pop();
        }
        reverse(remain.begin(), remain.end());
        
        reverse(target.begin(), target.end());
        for (int i = 0; i < remain.size(); i++)
        {
            string cur = "";
            if (!st.empty()) cur += st.top();
            cur += remain[i];

            if (cur == target)
            {
                ans += x <= y ? x : y;
                st.pop();
            } 
            else st.push(remain[i]);
        }
        

        return ans;
    }
};