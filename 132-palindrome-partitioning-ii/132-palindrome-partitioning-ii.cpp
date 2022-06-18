class Solution {
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j])    return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(isPalindrome(s, i, j))
            return dp[i][j] = 0;
        int mn = INT_MAX;
        for(int k = i; k < j; k++)
        {
            if(isPalindrome(s, i, k))
            {
                if(dp[k+1][j] == -1)  dp[k+1][j] = solve(s, k+1, j, dp);
                //int tempans = solve(str, i, k, dp) + solve(str, k+1, j, dp) + 1;
                mn = min(dp[k+1][j] + 1, mn);
            }
            
        }
        return dp[i][j] = mn;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, (vector<int>(n, -1)));
        return solve(s, 0, n-1, dp);
    }
};