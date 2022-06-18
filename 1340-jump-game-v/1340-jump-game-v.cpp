class Solution {
public:
    int n;
    int recur(vector<int> &arr, int d, vector<int> &dp, int i)
    {
        if(dp[i] != -1)
            return dp[i];
        // int k = i-1;
        int c1 = 0, c2 = 0;
        for(int k = i-1; k >= i-d && k>= 0; k--)
        {
            if(arr[i] <= arr[k])
                break;
            c1 = max(c1, recur(arr, d, dp, k));
        }
        for(int k = i+1; k <= i + d && k < n; k++)
        {
            if(arr[i] <= arr[k])
                break;
            c2 = max(c2, recur(arr, d, dp, k));
        }
        return dp[i] = 1 + max(c1, c2);
        
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;
        // int i = 10;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, recur(arr, d, dp, i));
        }
        // for(int i = 0; i <= 10; i++)
        //     cout<<dp[i]<<" ";
        return ans;
    }
};