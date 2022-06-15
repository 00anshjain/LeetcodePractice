class Solution {
public:
//     int recur(string &s, string &w, int n, int m, vector<vector<int>> &dp)
//     {
//         if(n == 0 || m == 0)
//             return 0;
//         if(dp[n][m] != -1)
//             return dp[n][m];
//         if(s[n-1] == w[m-1])
//             return dp[n][m] = 1 + recur(s, w, n-1, m-1, dp);
//         return dp[n][m] = max(recur(s, w, n-1, m, dp), recur(s, w, n, m-1, dp));

//     }
    int longestCommonSubsequence(string s, string w) {
        int n = s.size(), m = w.size();
        int dp[2][m+1];
        for(int i = 0; i <= m; i++)
            dp[0][i] = 0;
        for(int i = 0; i < 2; i++)
            dp[i][0] = 0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == w[j-1])
                    dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
                else
                    dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
            }
        }
        return dp[n%2][m];
        
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//         return recur(s, w, n, m, dp);
    }
};