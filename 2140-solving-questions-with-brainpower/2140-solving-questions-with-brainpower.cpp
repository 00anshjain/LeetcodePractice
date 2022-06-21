class Solution {
public:
    typedef long long ll;
    long long mostPoints(vector<vector<int>>& ques) {
        int n = ques.size();
        vector<ll> dp(n, 0l);
        ll ans = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int end = i + ques[i][1] + 1;   //to get profit after idle time of this work
            if(end < n)
               dp[i] = max(ans, ques[i][0] + dp[end]);
            else
                dp[i] = max(ans, (ll)ques[i][0]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};