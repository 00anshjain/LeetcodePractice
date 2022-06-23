class Solution {
public:
    int n;
    int recur(vector<int>& prices, vector<vector<vector<int>>>& dp, int ind, int buy, int cap)
    {
        if(ind == n || cap == 0)
            return 0;
        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        if(buy)
        {
            return dp[ind][buy][cap] = max(-prices[ind] + recur(prices, dp, ind+1, 0, cap) , 
                                          0 + recur(prices, dp, ind+1, 1, cap));
        }
        else{
            return dp[ind][buy][cap] = max(prices[ind] + recur(prices, dp, ind+1, 1, cap-1) , 
                                          0 + recur(prices, dp, ind+1, 0, cap));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // dp for index, buy(yes or no), capcity(0 - c)  
        return recur(prices, dp, 0, 1, k); //index 0, buy true, capacity = k 
        
        
    }
};