class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        if (target < *min_element(nums.begin(), nums.end())) return false;

        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            vector<bool> forCombi(n, false);
            for (int j = 0; j < i; j++)
                forCombi[n - 1 - j] = true;
            
            do
            {
                bool isCan = true;
                long long selected = target;
                long long unSelected = target;
                
                for (int i = 0; i < forCombi.size(); i++)
                {
                    if (forCombi[i] == 0 && unSelected % nums[i] == 0) unSelected /= nums[i];
                    else if (forCombi[i] == 1 && selected % nums[i] == 0) selected /= nums[i];  
                    else
                    {
                        isCan = false;
                        break;
                    }   
                }
                if (isCan && unSelected == selected) 
                {
                    // td::cout << unSelected << "\n";
                    return true;
                }
            
            } while(next_permutation(forCombi.begin(), forCombi.end()));
        }

        return false;   
    }
};