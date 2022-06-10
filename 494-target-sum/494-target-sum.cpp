class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // S1 - S2 = target -> eqn1
        // S1 + S2 = sum    -> eqn2
        //  eqn1 + eqn1 => 2S1 = target + sum
        // S1 = (target + sum) / 2
        // So our question reduces to count number of ways to get Sum S1.
        
        int t = (target + sum +1 )/2;
        if(t < 0 || t > sum || (target + sum)%2 != 0)//|| ((sum + t) %2 != 0))
            return 0;
        int n = nums.size();
        int dp[n+1][t+1];
        for(int i = 1; i < t+1; i++)
            dp[0][i] = 0;
        for(int i = 0; i < n+1; i++)
            dp[i][0] = 1;
        int cntZero = 0;
        for(int i = 1; i <= n; i++)
        {
            if(nums[i-1] == 0)
                cntZero++;
            for(int j = 1; j <= t; j++)
            {
                // dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1] && nums[i-1] != 0)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return pow(2, cntZero)*dp[n][t];
        
        
    }
};