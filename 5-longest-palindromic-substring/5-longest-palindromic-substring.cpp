class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int start = 0, end = 0;
        for(int i = 0; i < n-1; i++)
        {
            dp[i][i] = true;
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                start = i;
                end = i+1;
            }
        }
        dp[n-1][n-1] = true;
        for(int i = n-3; i >= 0; i--)
        {
            for(int j = i+2; j < n; j++)
            {
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    if(j - i > end - start)
                    {
                        end = j;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};