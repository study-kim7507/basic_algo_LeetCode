class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int sLength = s.size();
        string ans(sLength, '9');

        unordered_set<string> visit;
        queue<string> q;

        visit.insert(s);
        q.push(s);

        while (!q.empty())
        {
            string cur = q.front(); q.pop();
            ans = min(ans, cur);

            // operation : add
            string nxt1 = cur;
            for (int i = 1; i < sLength; i += 2)
                nxt1[i] = ((cur[i] - '0' + a) % 10) + '0';

            // operation : rotate
            string nxt2 = cur.substr(b) + cur.substr(0, b);
            
            if (!visit.count(nxt1)) 
            {
                visit.insert(nxt1);
                q.push(nxt1);
            }
            if (!visit.count(nxt2))
            {
                visit.insert(nxt2);
                q.push(nxt2);
            } 
        }        

        return ans;
    }
};