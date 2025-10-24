class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> edges(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int a, b;
            a = prerequisites[i][0];
            b = prerequisites[i][1];

            indegree[a]++;
            edges[b].push_back(a);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            for (auto nxt : edges[cur])
            {
                if (--indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        bool ans = true;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] != 0)
            {
                ans = false;
                break;
            }
        }

        return ans;
    }
};