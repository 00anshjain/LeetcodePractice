class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n%2 == 0)
            return true;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(i == j)
                    dp[i][j] = nums[i];
                else
                {
                    int a = nums[i] - dp[i+1][j];
                    int b = nums[j] - dp[i][j-1];
                    dp[i][j] = max(a, b);
                }
            }
        }
        return dp[0][n-1] >= 0;
        
    }
};