// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int mod = 1e9+7;
    typedef long long ll;
    int recur(int n, ll dp[])
    {
        if(n <= 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = (((1 * (ll)recur(n-1, dp) + ((n-1) * (ll)recur(n-2, dp)) % mod))%mod);
    }
    int countFriendsPairings(int n) 
    { 
        ll dp[n+1];
        memset(dp, -1l, sizeof(dp));
        return recur(n, dp);
        // code here
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends