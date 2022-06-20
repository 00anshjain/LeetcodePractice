// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int knap(int N, int W, int val[], int wt[], vector<vector<int>> &dp)
    // {
    //     if(dp[N][W] != -1)
    //         return dp[N][W];
    //     if(N == 0)
    //         return 0;
    //     if(wt[N-1] <= W)
    //         return dp[N][W] = max(knap(N, W-wt[N-1], val, wt, dp) + val[N-1], knap(N-1, W, val, wt, dp));
    //     return dp[N][W] = knap(N-1, W, val, wt, dp);
        
    // }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(2, vector<int>(W+1, 0));
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= W; j++)
            {
                if(j >= wt[i-1])
                    dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-wt[i-1]] + val[i-1]);
                else
                    dp[i%2][j] = dp[(i-1)%2][j];
            }
        }
        return dp[N%2][W];
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends