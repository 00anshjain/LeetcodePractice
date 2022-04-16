// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
        
        // int n = arr.size();
        int dp[n+1];
        // vector<int> dp(n+1, INT_MAX);
        // memset(dp, INT_MAX, sizeof(dp));
        for(int i = 1; i <= n; i++)
            dp[i] = INT_MAX;
        dp[0] = INT_MIN;
        // for(auto x : arr)
        for(int k = 0; k < n; k++)
        {
            int x = arr[k];
            int i = upper_bound(dp, dp+n+1, x) - dp;
            // int i = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
            if(dp[i] > x && dp[i-1] < x)
                dp[i] = x;
        }
        int i;
        for(i = n; i >= 0; i--)
        {
            if(dp[i] != INT_MAX)
                break;
        }
        return i;
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