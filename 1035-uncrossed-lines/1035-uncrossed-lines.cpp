class Solution {
public:
    int recur(int n, int m, vector<int> &a, vector<int> &b, vector<vector<int>> &dp)
    {
        if(dp[n][m] != -1)
            return dp[n][m];
        if(n == 0 || m == 0)
            return 0;
        int ans = 0;
        for(int i = n; i > 0; i--)
        {
            for(int j = m; j> 0; j--)
            {
                if(a[i-1] == b[j-1])
                    ans = max(ans, 1 + recur(i-1, j-1, a, b, dp));
            }
        }
        return dp[n][m] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return recur(n, m, nums1, nums2, dp);
    }
};