class Solution {
public:
    int n;
    // bool isPalin(string &s, int l, int r)
    // {
    //     while(l < r)
    //     {
    //         if(s[l++] != s[r--])
    //             return false;
    //     }
    //     return true;
    // }
    void recur(string &s, int i, vector<vector<string>>& res, vector<string> &cur, vector<vector<bool>>& dp)
    {
        if(i == n)
        {
            res.push_back(cur);
            return;
        }
        for(int j = i; j < n; j++)
        {
            if(dp[i][j])
            {
                cur.push_back(s.substr(i, j-i+1));
                recur(s, j+1, res, cur, dp);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int i = 0;
        n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n-1; i++)
        {
            dp[i][i] = true;
            if(s[i] == s[i+1])
                dp[i][i+1] = true;
            // else
            //     dp[i][i+1] = false;
        }
        dp[n-1][n-1] = true;
        for(int i = n-3; i >= 0; i--)
        {
            for(int j = i+2; j <n; j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
            }
        }
        vector<vector<string>> res;
        vector<string> cur;
        recur(s, i, res, cur, dp);
        return res;
    }
};