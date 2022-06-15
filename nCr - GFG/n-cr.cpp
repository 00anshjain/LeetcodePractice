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
        ll dp[r+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        // dp[0][1] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = min(i, r); j > 0 ; j--)
            {
                dp[j] = (dp[j] + dp[j-1])%mod;
            }
        }
        return (int)dp[r];
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