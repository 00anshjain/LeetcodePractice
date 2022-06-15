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
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        // dp[x] = 1;
        // dp[y] = 1;
        // dp[z] = 1;
        for(int i = 1; i <= n; i++)
        {
            int k = dp[i];
            if(i >= x && dp[i-x] != -1)
                k = max(k, 1 + dp[i-x]);
            if(i >= y && dp[i-y] != -1)
                k = max(k, 1 + dp[i-y]);
            if(i >= z && dp[i-z] != -1)
                k = max(k, 1 + dp[i-z]);
            dp[i] = k;
        }
        return dp[n] == -1 ? 0 : dp[n];
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