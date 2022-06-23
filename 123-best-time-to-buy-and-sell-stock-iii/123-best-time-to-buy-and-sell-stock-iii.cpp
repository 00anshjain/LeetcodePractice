class Solution {
public:
    // int n;
    // int recur(vector<int>& prices, vector<vector<vector<int>>>& dp, int ind, int buy, int cap)
    // {
    //     if(ind == n || cap == 0)
    //         return 0;
    //     if(dp[ind][buy][cap] != -1)
    //         return dp[ind][buy][cap];
    //     if(buy)
    //     {
    //         return dp[ind][buy][cap] = max(-prices[ind] + recur(prices, dp, ind+1, 0, cap) , 
    //                                       0 + recur(prices, dp, ind+1, 1, cap));
    //     }
    //     else{
    //         return dp[ind][buy][cap] = max(prices[ind] + recur(prices, dp, ind+1, 1, cap-1) , 
    //                                       0 + recur(prices, dp, ind+1, 0, cap));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int k = 2;
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        //index from 0 to n-1, but 0 or 1, capacity 0 to k;
        int dp[2][2][k+1];
        memset(dp, 0, sizeof(dp));
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap <= k; cap++)
                {
                    if(buy == 1)
                    {
                        dp[ind%2][buy][cap] = max(-prices[ind] + dp[(ind+1)%2][0][cap],
                                                        dp[(ind+1)%2][1][cap]);

                        // return dp[ind][buy][cap] = max(-prices[ind] + recur(dp, prices, ind+1, 0, cap), 
                        //                                         recur(dp, prices, ind+1, 1, cap));
                    }
                    else
                    {
                        dp[ind%2][buy][cap] = max(prices[ind] + dp[(ind+1)%2][1][cap-1], 
                                                            dp[(ind+1)%2][0][cap]);
                        // return dp[ind][buy][cap] = max(prices[ind] + recur(dp, prices, ind+1, 1, cap-1), 
                        //                                     recur(dp, prices, ind+1, 0, cap));
                    }
                }
            }
        }
        // recur(dp, prices, 0, 1, k);
        return dp[0][1][k];
    }
};