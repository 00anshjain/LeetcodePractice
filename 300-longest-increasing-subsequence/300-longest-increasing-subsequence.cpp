class Solution {
public:
    int recur(int i, int n, vector<int> &arr, vector<int> &dp)
    {
        int mx = 0;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] > arr[i])
            {
                mx = max(mx, dp[j]);
                // recur(j, n, arr);
            }
        }
        return mx + 1;
        // ans = max(ans, cnt);
    }
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n+1, 1);
        for(int i = n-2; i >= 0 ; i--)
            dp[i] = recur(i, n, a, dp);
        int mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, dp[i]);
        return mx;
    }
};