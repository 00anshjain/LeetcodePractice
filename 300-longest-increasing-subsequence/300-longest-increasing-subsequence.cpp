class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        // int n = arr.size();
        // int dp[n+1];
        // // vector<int> dp(n+1, INT_MAX);
        // // memset(dp, INT_MAX, sizeof(dp));
        // for(int i = 1; i <= n; i++)
        //     dp[i] = INT_MAX;
        // dp[0] = INT_MIN;
        // for(auto x : arr)
        // {
        //     int i = upper_bound(dp, dp+n+1, x) - dp;
        //     // int i = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        //     if(dp[i] > x && dp[i-1] < x)
        //         dp[i] = x;
        // }
        // int i;
        // for(i = n; i >= 0; i--)
        // {
        //     if(dp[i] != INT_MAX)
        //         break;
        // }
        // return i;
        int n = a.size();
        vector<int> dp(n, 1);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(a[j] < a[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};