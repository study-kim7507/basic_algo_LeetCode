class Solution {
public:
    char kthCharacter(int k) {
        queue<char> q;

        q.push('a');
        while (q.size() <= k)
        {
            string s1 = "", s2 = "";
            while (!q.empty())
            {
                auto cur = q.front(); q.pop();
                s1 += cur;

                if (cur == 'z') cur = 'a';
                else cur++;
                s2 += cur;
            }
            for (int i = 0; i < s1.size(); i++)
                q.push(s1[i]);
            for (int i = 0; i < s2.size(); i++)
                q.push(s2[i]);
        }

        for(int i = 0; i < k - 1; i++)
            q.pop();
        
        return q.front();
    }
};