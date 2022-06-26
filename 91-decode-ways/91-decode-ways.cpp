class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        if(s[0] == '0')
            return 0;
        else
            dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(s[i-1] != '0')
                dp[i] = dp[i-1];
            if(s[i-2] != '0')
            {
                if(stoi(s.substr(i-2, 2)) <= 26)
                    dp[i] += dp[i-2];
            }
        }
        // for(int i = 0; i <= n; i++)
        //     cout<<dp[i]<<" ";
        return dp[n];
    }
};