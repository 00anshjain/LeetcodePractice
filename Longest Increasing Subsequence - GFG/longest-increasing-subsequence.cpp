// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int ans = 0;
    int recur(int i, int n, int arr[], vector<int> &dp)
    {
        // if(i == n-1)
        // {
        //     ans = max(ans, cnt);
        //     return;
        // }
        int mx = 0;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                mx = max(mx, dp[j]);
                // recur(j, n, arr);
            }
        }
        return mx + 1;
        // ans = max(ans, cnt);
    }
    int longestSubsequence(int n, int a[])
    {
        ans = 0;
        vector<int> dp(n+1, 1);
        for(int i = n-1; i >= 0 ; i--)
            dp[i] = recur(i, n, a, dp);
        int mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, dp[i]);
        return mx;
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