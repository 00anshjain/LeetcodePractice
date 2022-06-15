class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 1)
                return 0;

        // int dp[n][2];
        // vector<vector<int>> dp(n, vector<int>(2, 1));
        // memset(dp, 1, sizeof(dp));
        int ma = 1, mi = 1;
        for(int i = 1; i < n; i++)
        {
            // for(int j = i-1; j >= 0; j--)
            // {
                if(nums[i] > nums[i-1])
                {
                    ma = mi + 1;
                    // dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
                else if(nums[i] < nums[i-1])
                {
                    // dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                    mi = ma + 1;
                }
            // }
        }
        return max(ma, mi);
    }
};