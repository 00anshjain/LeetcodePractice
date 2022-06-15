// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    typedef long long ll;
    int nCr(int n, int r){
        if(r > n)
            return 0;
        r = min(r, n-r);
        ll dp[n+1][r+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= min(i+1,r); j++)
            {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
            }
        }
        return (int)dp[n-1][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends