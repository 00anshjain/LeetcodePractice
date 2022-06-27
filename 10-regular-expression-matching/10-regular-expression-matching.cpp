class Solution {
public:
    //  Read this from discussion => for ".*" => {".", "..", "...", "....", }     
    // ".* " -> "..* " -> ".." -> "a." -> "ab". It matches.
    // The "*" is attached to ".", so, you just make another ".".
    bool recur(string &s, string &p, int i, int j, vector<vector<bool>>& dp)
    {
        if(i == 0 && j == 0)
            return true;
        if(j == 0)
            return false;
        if(dp[i][j] == false)
            return false;
        if(i == 0)
        {
            if(p[j-1] != '*')
                return dp[i][j] = false;
            return dp[i][j] = recur(s, p, i, j-2, dp);
        }
        if(s[i-1] == p[j-1] || p[j-1] == '.')
        {
            return dp[i][j] = recur(s, p, i-1, j-1, dp);
        }
        if(p[j-1] == '*')
        {
            bool k = recur(s, p, i, j-2, dp);
            if(k)
                return k;
            if(p[j-2] == '.')
            {
                // p[j-2] = s[i-1];
                return dp[i][j] = recur(s, p, i-1, j, dp);
            }
            if(p[j-2] == s[i-1])
                return dp[i][j] = recur(s, p, i-1, j, dp);
            return dp[i][j] = false;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, true)); //true means not visited
        // if visited and answer not found we return false
        // As soon as we found true, we dont make any further recursion call, we just return back with true
        // So true will never be used so we itnitialise it with true;        
        return recur(s, p, n, m, dp);
        
    }
};