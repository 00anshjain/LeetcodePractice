// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int recur(int n, int x, int y, int z, vector<int>& dp)
    {
        if(n < 0)
            return INT_MIN;
        if(n == 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        int a, b, c;
        a = recur(n - x, x, y, z, dp);
        b = recur(n - y, x, y, z, dp);
        c = recur(n - z, x, y, z, dp);
        int ans = max(max(a, b), c);
        if(ans != INT_MIN)
            return dp[n] = ans + 1;
        return dp[n] = ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, -1);
        int k = recur(n, x, y, z, dp);
        if(k == INT_MIN)
            return 0;
        return k;
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