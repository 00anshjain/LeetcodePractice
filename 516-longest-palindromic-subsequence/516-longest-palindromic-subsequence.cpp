class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string k = s;
        int dp[n][n];
        int ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            dp[i][i] = 1;
            ans = 1;
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 2;
                ans = 2;
            }
            else
                dp[i][i+1] = 1;
        }
        
        dp[n-1][n-1] = 1;
        ans = max(ans, dp[n-1][n-1]);
        for(int i = n-3; i>= 0; i--)
        {
            for(int j = i+2; j< n; j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};