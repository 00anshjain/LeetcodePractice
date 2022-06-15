class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // int dp[n][2];
        vector<vector<int>> dp(n, vector<int>(2, 1));
        // memset(dp, 1, sizeof(dp));
        for(int i = 1; i < n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(nums[j] > nums[i])
                {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
                else if(nums[j] < nums[i])
                {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 2; j++)
                ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};