class Solution {
public:
    int bfs(int stIdx, int stDir, vector<int> nums, int cnt)
    {
        int n = nums.size();
        queue<pair<int, int>> q;
        q.push({stIdx, stDir});

        while (!q.empty())
        {
            int curIdx, curDir;
            tie(curIdx, curDir) = q.front(); q.pop();
            
            // 왼쪽 이동
            if (curDir == 0)
            {
                curIdx--;
                while (curIdx >= 0 && nums[curIdx] == 0)
                    curIdx--;
                if (curIdx >= 0)
                {
                    nums[curIdx]--;
                    cnt--;

                    q.push({curIdx, 1});
                }
            } 
            // 오른쪽 이동
            else if (curDir == 1)
            {
                curIdx++;
                while(curIdx < nums.size() && nums[curIdx] == 0)
                    curIdx++;
                if (curIdx < nums.size())
                {
                    nums[curIdx]--;
                    cnt--;

                    q.push({curIdx, 0});
                }
            }
        }
        
        if (cnt == 0) return 1;
        return 0;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (auto num : nums)
            if (num != 0) cnt += num;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans += bfs(i, 0, nums, cnt);
                ans += bfs(i, 1, nums, cnt);
            }
        }

        return ans;
    }
};