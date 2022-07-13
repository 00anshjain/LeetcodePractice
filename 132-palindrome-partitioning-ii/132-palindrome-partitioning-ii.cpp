class Solution {
public:
    int n;
    int recur(string &s, int i, vector<int> &dp, vector<vector<bool>>& palin)
    {
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for(int j = i; j < n; j++)
        {
            if(palin[i][j])
            {
                int k = recur(s, j+1, dp, palin);
                if(k != INT_MAX)
                    ans = min(ans, 1+k);
            }
        }
        // if(ans == INT_MAX)
        //     return dp[i] = INT_MAX;
        return dp[i] = ans;
    }
    int minCut(string s) {
        n = s.size();
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
        {
            palin[i][i] = true;
            if(i+1 < n && (s[i] == s[i+1]))
            {
                palin[i][i+1] = true;
            }
        }
        for(int i = n-3; i >= 0; i--)
        {
            for(int j = i+2; j<n; j++)
            {
                if(s[i] == s[j])
                    palin[i][j] = palin[i+1][j-1];
            }
        }
        
        vector<int> dp(n, -1);
        return recur(s, 0, dp, palin)-1;
    }
};