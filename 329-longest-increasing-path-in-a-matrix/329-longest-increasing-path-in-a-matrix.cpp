class Solution {
public:
    int n, m;
    int recur(int i, int j, int cnt, vector<vector<int>> &dp, vector<vector<int>> &t)
    {
    // ans = max(ans, cnt);
        if(t[i][j] != -1)
            return t[i][j];
        int k = dp[i][j];
        int ans = 0;
        // dp[i][j] = -1;
        if(i-1 >= 0 && dp[i-1][j] > k)
        {
            ans = max(ans, recur(i-1, j, cnt+1, dp, t));
        }
        if(j-1 >= 0 && dp[i][j-1] > k)
        {
            ans = max(ans, recur(i, j-1, cnt+1, dp, t));
        }
        if(j+1 < m && dp[i][j+1] > k)
        {
            ans = max(ans, recur(i, j+1, cnt+1, dp, t));
        }
        if(i+1 < n && dp[i+1][j] > k)
        {
            ans = max(ans, recur(i+1, j, cnt+1, dp, t));
        }
        // dp[i][j] = k;
        return t[i][j] = 1 + ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> t(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = max(ans, recur(i, j, 1, matrix, t));
            }
        }
        return ans;
    }
};