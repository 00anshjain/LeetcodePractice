class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto x : nums)
            mp[x]++;
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto x : mp)
            bucket[x.second].push_back(x.first);
        vector<int> ans;
        for(int i = n; i >= 0 && k > 0; i--)
        {
            for(auto x : bucket[i])
            {
                ans.push_back(x);
                k--;
                if(k == 0)
                    break;
            }
        }
        return ans;
    }
};