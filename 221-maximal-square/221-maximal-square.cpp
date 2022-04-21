class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int mx = 0;
        for(int i = 0; i < m; i++)
        {
            dp[0][i] = matrix[0][i] - '0';
            if(dp[0][i] == 1)
                mx = 1;
        }
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
            mx = max(mx, dp[i][0]);
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]),dp[i][j-1]) + 1;
                    mx = max(mx, dp[i][j]);
                }
                // else
                //     dp[i][j] = 0;
                
            }
        }
        return mx*mx;
        
    }
};