class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n-1; i++)
        {
            dp[i][i] = true;
            if(s[i] == s[i+1])
                dp[i][i+1] = true;
        }
        dp[n-1][n-1] = true;
        
        for(int i = n-3; i >= 0; i--)
        {
            for(int j = i+2; j < n; j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
            }
        }
        for(int i = 0; i < n-2; i++)
        {
            if(dp[0][i])
            {
                for(int j = i+1; j < n-1; j++)
                {
                    if(dp[i+1][j] && dp[j+1][n-1])
                        return true;
                }
            }
        }
        return false;
    }
};