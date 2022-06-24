class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            // dp[i][0] = matrix[i][0] == '0' ? 0 : dp[i-1][0] + 1;    
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                if(i > 0)
                    dp[i][j] = 1 + dp[i-1][j];
                else
                    dp[i][j] = 1;
                int k = j;
                int smallest = dp[i][k];
                while(k >= 0 && dp[i][k] > 0)
                {
                    smallest = min(smallest, dp[i][k]);
                    ans = max(ans, smallest * (j - k + 1));
                    k--;
                }
            }
        }
        return ans;
    }
};