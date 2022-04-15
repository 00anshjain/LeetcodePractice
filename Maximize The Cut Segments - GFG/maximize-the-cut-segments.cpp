// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, 0);
        if(x <= n)
            dp[x] = 1;
        if(y <= n)
            dp[y] = 1;
        if(z <= n)
            dp[z] = 1;
        // int dp[n+1];
        // dp[0] = 1;
        // memset(dp, 1, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            // dp[i] = 1;
            if(i >= x && dp[i-x] != 0)
            {
                // if(dp[i-x] != 0)
                    dp[i] = dp[i-x] + dp[x];
            }
            if(i >= y && dp[i-y] != 0)
            {
                dp[i] = max(dp[i], dp[i-y] + dp[y]);
            }
            if(i >= z && dp[i-z] != 0)
            {
                dp[i] = max(dp[i], dp[i-z] + dp[z]);
            }
        }
        // for(int i = 0;i <= n; i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        return dp[n];
        //Your code here
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends