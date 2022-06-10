// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int KnapSack(int W, int wt[], int val[], int n, vector<vector<int>>& dp)
    {
        if(W == 0 || n == 0)
            return 0;
        if(dp[W][n] != -1)
            return dp[W][n];
        if(wt[n-1] <= W)
        {
            return dp[W][n]= max(KnapSack(W-wt[n-1], wt, val, n-1, dp) + val[n-1], KnapSack(W, wt, val, n-1, dp));
        }
        return  dp[W][n] = KnapSack(W, wt, val, n-1, dp);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
        return KnapSack(W, wt, val, n, dp);
       // Your code here
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends