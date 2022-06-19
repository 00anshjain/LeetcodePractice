class Solution {
public:
    // bool isPalindrome(string &s, int i, int j)
    // {
    //     while(i <= j)
    //     {
    //         if(s[i] != s[j])    return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    int solve(string &s, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        // if(palin[i][j])
        //     return dp[i][j] = 0;
        int mn = INT_MAX;
        for(int k = i; k < j; k++)
        {
            if(dp[i][k] == -1)  dp[i][k] = solve(s, i, k, dp);
            if(dp[k+1][j] == -1)  dp[k+1][j] = solve(s, k+1, j, dp);
            //int tempans = solve(str, i, k, dp) + solve(str, k+1, j, dp) + 1;
            mn = min(dp[i][k] + dp[k+1][j] + 1, mn);
        }
        return dp[i][j] = mn;
    }
    int minCut(string s) {
        int n = s.size();
        int cut[n];
        for(int i = 0; i < n; i++)
            cut[i] = i;
        //to find out how many cut needed for string of size i 
        vector<vector<bool>> dp(n, (vector<bool>(n, false)));
        for(int j = 0; j < n; j++)  // string start se end tak h,  end = j
        {
            for(int i = j; i >= 0; i--)     // start changing;
            {
                if(s[i] == s[j] && ((j - i + 1 <= 2) || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    if(i != 0)
                        cut[j] = min(cut[j], cut[i-1] + 1);
                    else
                        cut[j] = 0;
                        // i = 0 mtlb starting se yaha tak aaye koi cut nhi lagana pada
                }
            }
        }
        return cut[n-1];
    }
};