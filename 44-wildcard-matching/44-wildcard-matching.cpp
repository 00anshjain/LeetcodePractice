class Solution {
public:
    bool recur(string &s, string &p, int i, int j, vector<vector<bool>> &dp)
    {
        if(i == 0 && j == 0)
            return true;
        if(dp[i][j] != true)
            return dp[i][j];
        if(j == 0)
            return dp[i][j] = false;
        if(i == 0)
        {
            if(p[j-1] != '*')
                return dp[i][j] = false;
            return dp[i][j] = recur(s, p, i, j-1, dp);
        }
        if(s[i-1] == p[j-1] || p[j-1] == '?')
        {
            return dp[i][j] = recur(s, p, i-1, j-1, dp);
        }
        if(p[j-1] == '*')
        {
            return dp[i][j] = (recur(s, p, i, j-1, dp) || recur(s, p, i-1, j, dp));
            
            // if(k)
            //     return k;
            // if(p[j-2] == '?')
            // {
            //     // p[j-2] = s[i-1];
            //     return recur(s, p, i-1, j);
            // }
            // if(p[j-2] == s[i-1])
            //     return recur(s, p, i-1, j);
            // return false;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // dp intialised by true
        // not taken int, takenbool type dp to save space
        // basically whenever we get true in return we will return back till the start
        // but whenerver we get false we have to save the result in dp, so that if same situation comes we 
        // have result stored
        //As we get true, we dont make recusrive calls, we just return back, so need to save in dp
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, true));
        return recur(s, p, n, m, dp);
    }
};