class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, INT_MAX);
        int ans = 0;
        dp[0] = INT_MIN;
        for(auto x : nums)
        {
            int i = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
            if(x < dp[i] && x > dp[i-1])
            {
                dp[i] = x;
                ans = max(ans, i);
            }
            // cout<<x<<" "<<dp[i]<<" "<<dp[i-1]<<" "<<i<<endl;
        }
        return ans;
        
    }
};