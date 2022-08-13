class Solution {
public:
    int numSquares(int n) {
        vector<int> arr;
        int i = 0;
        while(i*i <= n)
        {
            arr.push_back(i*i);
            i++;
        }
        int m = arr.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX-1));
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++)
        {
            dp[i][0] = 0;
            for(int j = 0; j <= n; j++)
            {
                if(j >= arr[i-1])
                {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-arr[i-1]]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
        
        
    }
};