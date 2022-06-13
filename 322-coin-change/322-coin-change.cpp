class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int dp[n+1][amount+1];
        vector<vector<int>>dp(n+1, vector<int>(amount+1, INT_MAX));
        dp[0][0] = 0;
        // memset(dp, INT_MAX, sizeof(dp));
        // for(int i = 0; i <= n; i++)
        // {
        //     for(int j = 0; j <= amount; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
            for(int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j >= coins[i-1] && dp[i][j-coins[i-1]] < dp[i][j])
                    dp[i][j] = 1 + dp[i][j-coins[i-1]];
                // else
                //     dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};