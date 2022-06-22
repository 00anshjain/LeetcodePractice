// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    int n = price.size();
    int dp[n];
    memset(dp, 0,sizeof(dp));
    // dp[0][0] = 0;
    // dp[0][1] = 0;
    dp[0] = 0;
    int mnBuy = price[0];
    for(int i = 1; i < n; i++)
    {
        mnBuy = min(mnBuy, price[i]);
        dp[i] = max(dp[i-1], price[i] - mnBuy);
    }
    int mxSell = price[n-1];
    for(int i = n-2; i >= 0; i--)
    {
        mxSell = max(mxSell, price[i]);
        dp[i] = max(dp[i+1], dp[i] + mxSell - price[i]);
        // ans = max(ans, dp[i]);
    }
    return dp[0];
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