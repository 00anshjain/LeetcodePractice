class Solution {
public:
    int recur(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n == 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        for(int j = 0; j < n; j++)
        {
            if(nums[j] + j >= n)
            {
                return dp[n] = 1 + recur(nums, j, dp);
            }
        }
        return dp[n] = INT_MAX;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int k = recur(nums, n-1, dp);
        return k == INT_MAX ? -1 : k;
    }
};