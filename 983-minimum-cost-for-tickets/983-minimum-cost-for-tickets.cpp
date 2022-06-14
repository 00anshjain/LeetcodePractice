class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[367];
        dp[366] = 0;
        unordered_set<int> st(days.begin(), days.end());
        for(int i = 365; i>= 0; i--)
        {
            if(st.find(i) == st.end())
            {
                dp[i] = dp[i+1];
            }
            else
            {
                dp[i] = costs[0] + dp[i+1];
                if(i + 7 <= 366)
                {
                    dp[i] = min(dp[i], dp[i+7] + costs[1]);
                }
                else
                    dp[i] = min(dp[i], costs[1]);
                if(i + 30 <= 366)
                {
                    dp[i] = min(dp[i], dp[i+30] + costs[2]);
                }
                else
                    dp[i] = min(dp[i], costs[2]);
            }
        }
        return dp[0];
        
    }
};