class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans(nums.begin(), nums.end());
        sort(ans.begin(), ans.end(), greater<int>());
        
        // accumulate(nums.begin(), nums.begin() + k, 0);
        // for(auto x : nums)
        //     mp[x]++;
        // priority_queue<int> pq;
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++)
            mp[ans[i]]++;
        vector<int> v;
        for(auto x : nums)
        {
            if(mp[x] > 0)
            {
                v.push_back(x);
                mp[x]--;
            }
        }
        return v;
    }
};