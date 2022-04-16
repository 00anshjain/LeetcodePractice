class Solution {
public:
    int ans = 0;
    int recur(string &s, int i, int j, vector<vector<int>> &dp, int n1, int n2)
    {
        // if(i == 0 || j == 0)
        //     return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i > j)
            return dp[i][j] = 0;
        else if(i == j)
            return dp[i][j] = 1; 
        else if(s[i] == s[j])
        {
            dp[i][j] =  2 + recur(s, i+1, j-1, dp, n1, n2);
            if(i < n1 && j >= n1)
                ans = max(ans, dp[i][j]);
            return dp[i][j];
        }
        // else
            return dp[i][j] = max(recur(s, i, j-1, dp, n1, n2), recur(s, i+1, j, dp, n1, n2));
        // cout<<dp[i][j]<<" ";
        // return dp[i][j];
    }
    int longestPalindrome(string s1, string s2) {
        string s = s1 + s2;
        ans = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        recur(s, 0, n-1, dp, n1, n2);
        return ans;
        // string k = s;
        // reverse(k.begin(), k.end());
        // int dp[n+1][n+1];
        // int ans = 0;
        // memset(dp, 0, sizeof(dp));
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j <= n; j++)
        //     {
        //         if(s[i-1] == k[j-1])
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         else
        //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //     }
        // }
        // if(dp[n][n1] == 0)
        //     return 0;
        // else if(dp[n][n] - dp[n][n1] == 0)
        //     return 0;
        // return dp[n][n];
    }
};