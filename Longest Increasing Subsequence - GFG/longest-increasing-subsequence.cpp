// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        int ans = 0;
        for(int j = 0; j < n; j++)
        {
            int x = a[j];
            int i = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
            if(dp[i] > x && dp[i-1] < x)
            {
                dp[i] = x;
                ans = max(ans, i);
            }
            // ans = max(ans, dp[i]);
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