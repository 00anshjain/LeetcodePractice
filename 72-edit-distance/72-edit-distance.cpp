class Solution {
public:
    int recur(string &w, string &s, vector<vector<int>>& dp, int n, int m)
    {
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(w[n-1] == s[m-1])
            return dp[n][m] = recur(w, s, dp, n-1, m-1);
        return dp[n][m] = 1 + min(min(recur(w, s, dp, n-1, m-1), recur(w, s, dp, n, m-1)), recur(w, s, dp, n-1, m));
        
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // int dp[n+1][m+1];
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recur(word1, word2, dp, n, m);
        // for(int i = 0; i <= n; i++)
        //     dp[i][0] = i;
        // for(int i = 0; i <= m; i++)
        //     dp[0][i] = i;
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j <= m; j++)
        //     {
        //         if(word1[i-1] == word2[j-1])
        //         {
        //             dp[i][j] = dp[i-1][j-1];
        //         }
        //         else
        //         {
        //             dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        //         }
        //     }
        // }
        // return dp[n][m];
        
    }
};