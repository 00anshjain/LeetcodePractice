class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> p(n, 0);
        unordered_map<int, int> mp, ump;
        int sum = 0;
        mp[0] = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            mp[sum] = i+1;
        }
        sum = 0;
        ump[0] = 0;
        for(int i = n-1; i >= 0; i--)
        {
            sum += nums[i];
            ump[sum] = n-i;
        }
        int ans = INT_MAX;
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if(itr->first <= target)
            {
                if(ump.find(target - itr->first) != ump.end())
                {
                    int k = itr->second + ump[target - itr->first];
                    if(k > n)
                        continue;
                    ans = min(ans, k);
                }
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};