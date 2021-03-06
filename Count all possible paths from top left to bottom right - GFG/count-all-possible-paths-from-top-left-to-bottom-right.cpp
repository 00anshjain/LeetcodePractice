// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    typedef long long ll;
    ll ans;
    int mod = 1e9+7;
    long long int numberOfPaths(int m, int n){
        ans = 0;
        vector<ll> dp(n, 1);
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
                dp[j] = (dp[j] + dp[j-1])%mod;
        }
        return dp[n-1];
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends