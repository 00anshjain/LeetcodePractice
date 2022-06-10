class Solution {
public:
    int getCount(vector<int> &nums, int target, int n, vector<vector<int>> &dp)
    {
        // if(target == 0)
        //     return 1;
        if(n == 0)
        {
            if(target == 0)
                return 1;
            return 0;
        }if(dp[n][target + 2000] != -1)
            return dp[n][target + 2000];
        // if(nums[n-1] <= target)
        // {
            return dp[n][target + 2000] = getCount(nums, target + nums[n-1], n-1, dp) + getCount(nums, target - nums[n-1], n-1, dp);
        // }
        // return dp[n][target + 1000] = getCount(nums, target, n-1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(4002, -1));
        return getCount(nums, target, n, dp);
    }
};