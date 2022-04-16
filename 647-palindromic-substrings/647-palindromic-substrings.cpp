class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        for(int i = 0; i < n-1; i++)
        {
           dp[i][i] = true;
            if(s[i] == s[i+1])
                dp[i][i+1] = true;
        }
        dp[n-1][n-1] = true;
        for(int i = n-3; i>= 0; i--)
        {
            for(int j = i+2; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n ; j++)
                if(dp[i][j])
                    cnt++;
        }
        return cnt;
    }
};