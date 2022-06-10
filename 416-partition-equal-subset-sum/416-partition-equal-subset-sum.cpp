class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum, vector<vector<int>> &dp, int n)
    {
        if(sum == 0)
            return true;
        if(n == 0)
            return false;
        if(dp[n][sum] != -1)
            return dp[n][sum];
        if(nums[n-1] <= sum)
            return  dp[n][sum]= subsetSum(nums, sum - nums[n-1], dp, n-1) || subsetSum(nums, sum, dp, n-1);
        return dp[n][sum]= subsetSum(nums, sum, dp, n-1);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum & 1) == 1)
            return false;
        sum /= 2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        // for(int i = 1; i <= sum; i++)
        //     dp[0][i] = 0;
        // for(int i = 0; i<=n; i++)
        //     dp[i][0] = 1;
        return subsetSum(nums, sum, dp, n);
        
    }
};