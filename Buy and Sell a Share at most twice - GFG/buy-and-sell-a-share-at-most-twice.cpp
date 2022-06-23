// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
    // int n;

    // int recur(vector<vector<vector<int>>>& dp, vector<int>& prices, int ind, int buy, int cap)
    // {
    //     if(cap == 0 || ind == n)
    //         return 0;
    //     if(dp[ind][buy][cap] != -1)
    //         return dp[ind][buy][cap];
    //     if(buy == 1)
    //     {
    //         return dp[ind][buy][cap] = max(-prices[ind] + recur(dp, prices, ind+1, 0, cap), 
    //                                                 recur(dp, prices, ind+1, 1, cap));
    //     }
    //     else
    //     {
    //         return dp[ind][buy][cap] = max(prices[ind] + recur(dp, prices, ind+1, 1, cap-1), 
    //                                             recur(dp, prices, ind+1, 0, cap));
    //     }
    // }
int maxProfit(vector<int>&prices){
    int k = 2;
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    //index from 0 to n-1, but 0 or 1, capacity 0 to k;
    int dp[n+1][2][k+1];
    memset(dp, 0, sizeof(dp));
    for(int ind = n-1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int cap = 1; cap <= k; cap++)
            {
                if(buy == 1)
                {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],
                                                    dp[ind+1][1][cap]);
                    
                    // return dp[ind][buy][cap] = max(-prices[ind] + recur(dp, prices, ind+1, 0, cap), 
                    //                                         recur(dp, prices, ind+1, 1, cap));
                }
                else
                {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 
                                                        dp[ind+1][0][cap]);
                    // return dp[ind][buy][cap] = max(prices[ind] + recur(dp, prices, ind+1, 1, cap-1), 
                    //                                     recur(dp, prices, ind+1, 0, cap));
                }
            }
        }
    }
    // recur(dp, prices, 0, 1, k);
    return dp[0][1][k];
    // return ans;
    //Write your code here..
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends