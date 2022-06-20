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
    int M, N;
    ll DFS(int i, int j, vector<vector<ll>> &dp)
    {
        
        if(i == M-1 && j == N-1)
            return 1;
        if(i >= M || j>= N)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0l;
        ans += DFS(i+1, j, dp);
        ans %= mod;
        ans += DFS(i, j+1, dp);
        ans %= mod;
        return dp[i][j] = ans;
        
    }
    long long int numberOfPaths(int m, int n){
        ans = 0;
        M = m;
        N = n;
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, -1));
        return DFS(0, 0, dp);
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