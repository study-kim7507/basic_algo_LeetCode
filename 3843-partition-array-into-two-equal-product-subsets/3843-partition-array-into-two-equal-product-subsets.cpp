class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            vector<bool> forCombi(n, false);
            for (int j = 0; j < i; j++)
                forCombi[n - 1 - j] = true;
            
            do
            {
                __int128 selected = 1;
                __int128 unSelected = 1;
                
                for (int i = 0; i < forCombi.size(); i++)
                {
                    if (forCombi[i] == 0) unSelected *= nums[i];
                    else selected *= nums[i];              
                }
                if (unSelected == selected && selected == target) return true;
            } while(next_permutation(forCombi.begin(), forCombi.end()));
        }

        return false;   
    }
};