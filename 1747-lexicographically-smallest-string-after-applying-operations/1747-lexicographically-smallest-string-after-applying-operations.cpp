class Solution {
public:
    string ans = "";
    unordered_set<string> visit;

    void dfs(string curString, int a, int b)
    {
        if (visit.find(curString) != visit.end())
        {
            if (ans.empty()) ans = curString;
            else ans = min(ans, curString);

            return;
        }

        visit.insert(curString);
        
        // operation : add
        string newString1 = curString;
        for (int i = 1; i < newString1.size(); i += 2)
        {
            int target = newString1[i] - '0';
            target += a;
            if (target >= 10) target -= 10;
            newString1[i] = target + '0';
        }
        dfs(newString1, a, b);

        // operation : rotate
       int len = curString.size();
        int rot = b % len;
        string prefix = curString.substr(0, len - rot);
        string postfix = curString.substr(len - rot);
        string newString2 = postfix + prefix;
        dfs(newString2, a, b);
    }

    string findLexSmallestString(string s, int a, int b) {
        dfs(s, a, b);

        return ans;
    }
};