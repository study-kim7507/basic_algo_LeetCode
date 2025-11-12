class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt1, cnt2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int i = 0; i < nums1.size(); i++)
            cnt1[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++)
            cnt2[nums2[i]]++;
    }
    
    void add(int index, int val) {
        cnt2[nums2[index]]--;
        nums2[index] += val;
        cnt2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto e : cnt1)
        {
            int n1 = e.first;
            int c1 = e.second;

            if (cnt2.find(tot - n1) == cnt2.end())
                continue;

            int n2 = tot - n1;
            int c2 = cnt2[n2];
            
            ans += c1 * c2;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */