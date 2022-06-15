// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    // int recur(int j, int a[], vector<int> &dp)
    // {
    //     if(j < 0)
    //         return 0;
    //     if(dp[j] != -1)
    //         return dp[j];
    //     int ans = 1;
    //     for(int i = j-1; i>= 0; i--)
    //     {
    //         if(a[i] < a[j])
    //             ans = max(ans, 1 + recur(i, a, dp));
                
    //     }
    //     return dp[j] = ans;
    // }
    int longestSubsequence(int n, int a[])
    {
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // vector<int> dp(n, -1);
        // int ans = 0;
        // for(int i = 0; i < n; i++)
        //     ans =  max(ans, recur(i, a, dp));
        // return ans;
        vector<int> dp(n, 1);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(a[j] < a[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
       // your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends