class Solution {
public:
    int LCS(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
    {
        if(n == 0 || m == 0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(s1[n-1] == s2[m-1])
            return dp[n][m] = 1 + LCS(s1, s2, n-1, m-1, dp);
        return dp[n][m] = max(LCS(s1, s2, n, m-1, dp), LCS(s1, s2, n-1, m, dp));
    }
    int minDistance(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        int a = LCS(s1, s2, s1.size(), s2.size(), dp);
        return s1.size() + s2.size() - 2*a;
    }
};