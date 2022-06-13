class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        int dp[n][n];
        for(int i = 0; i < n-1; i++)
        {
            dp[i][i] = 1;
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        }
        dp[n-1][n-1] = 1;
        for(int i = n-3; i >= 0; i--)
        {
            for(int j = i+2; j< n; j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        int n1 = word1.size();
        int n2 = word2.size();
        int ans = 0;
        for(int i = 0; i < n1; i++)
        {
            for(int j = 0; j < n2; j++)
            {
                if(word1[i] == word2[j])
                {
                    ans = max(ans, dp[i][n1 + j]);
                }
            }
        }
        return ans;
    }
};