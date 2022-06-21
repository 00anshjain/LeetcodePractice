class Solution {
public:
    typedef long long ll;
    long long mostPoints(vector<vector<int>>& ques) {
        int n = ques.size();
        ll ans = 0l; 
        vector<vector<ll>> dp(n, vector<ll>(2, 0l)); //isko leke profit, isko liye/bina liye maxm profit
        // vector<vector<ll>> dp[n][2];   
        // memset(dp, 0l, sizeof(dp));
        for(int i = n-1; i >= 0; i--)
        {
            int end = i + ques[i][1] + 1;   //to get profit after idle time of this work
            if(end < n)
               dp[i][0] = ques[i][0] + max(dp[end][0], dp[end][1]);
            else
                dp[i][0] = ques[i][0];
            ans = max(ans, dp[i][0]);
            dp[i][1] = ans;
        }
        return ans;
        // for(int i = 0; i < n; i++)
        //     ans = max(ans, dp[i]);
        // return max(ans, dp[n]);
    }
};