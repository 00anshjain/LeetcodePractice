class Solution {
public:
    int recur(string &s, string &w, int n, int m, vector<vector<int>> &dp)
    {
        if(n == 0 || m == 0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(s[n-1] == w[m-1])
            return dp[n][m] = 1 + recur(s, w, n-1, m-1, dp);
        return dp[n][m] = max(recur(s, w, n-1, m, dp), recur(s, w, n, m-1, dp));

    }
    int longestCommonSubsequence(string s, string w) {
        int n = s.size(), m = w.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recur(s, w, n, m, dp);
    }
};