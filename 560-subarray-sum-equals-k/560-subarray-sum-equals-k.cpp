class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int s = 0, ans = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            s += nums[i];
            if(mp.find(s-k) != mp.end())
                ans += mp[s - k];
            mp[s]++;
        }
        return ans;
        
    }
};