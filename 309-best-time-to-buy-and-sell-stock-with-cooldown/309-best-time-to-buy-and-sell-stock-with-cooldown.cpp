class Solution {
public:
    int n;
    int recur(vector<int> &prices, vector<vector<int>> &dp, int ind, int buy)
    {
        if(ind >= n)
            return 0;
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy] = max(-prices[ind] + recur(prices, dp, ind+1, 0),
                                     recur(prices, dp, ind+1, 1));
        }
        else
            return dp[ind][buy] = max(prices[ind] + recur(prices, dp, ind+2, 1),
                                     recur(prices, dp, ind+1, 0));
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // 0 to n-1 index, buy = 0, 1;
        return recur(prices, dp, 0, 1);    
    }
};