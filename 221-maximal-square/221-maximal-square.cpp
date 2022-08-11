class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++)
        {
            if(mat[0][i] == '1')
            {
                dp[0][i] = 1;
                ans = 1;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(mat[i][0] == '1')
            {
                dp[i][0] = 1;
                ans = 1;
            }
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(mat[i][j] == '1')
                {
                    dp[i][j]= 1 + min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
        
    }
};