class Solution {
public:
    int recur(vector<vector<int>> &dp, string &w1, string &w2, int n, int m)
    {
        if(n == 0)
            return m;
        if(m == 0)
            return n;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(w1[n-1] == w2[m-1])
            return dp[n][m] = recur(dp, w1, w2, n-1, m-1);
        return dp[n][m] = min(min(1 + recur(dp, w1, w2, n-1, m), 1 + recur(dp, w1, w2, n, m-1)), 1 + recur(dp, w1, w2, n-1, m-1));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recur(dp, word1, word2, n, m);
        
    }
};