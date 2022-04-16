class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1];
        // vector<int> dp(n+1, INT_MAX);
        // memset(dp, INT_MAX, sizeof(dp));
        for(int i = 1; i <= n; i++)
            dp[i] = INT_MAX;
        dp[0] = INT_MIN;
        for(auto x : arr)
        {
            int i = upper_bound(dp, dp+n+1, x) - dp;
            // int i = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
            if(dp[i] > x && dp[i-1] < x)
                dp[i] = x;
        }
        int i;
        for(i = n; i >= 0; i--)
        {
            if(dp[i] != INT_MAX)
                break;
        }
        return i;
    }
};