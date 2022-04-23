// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
// typedef long long ll;
long long int count(long long int n)
{
	long long int dp[n+1],i;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;                 // If 0 sum is required number of ways is 1.
// 	for(ll i = 3; i < min(n+1, (ll)3); i++)
// 	{
// 	    dp[i] = 0;
// 	}
	for(i = 3; i < n+1; i++)
	{
	    dp[i] += dp[i-3];
	}
	for(i = 5; i < n+1; i++)
	{
	    dp[i] += dp[i-5];
	}
	for(i = 10; i < n+1; i++)
	{
	    dp[i] += dp[i-10];
	}
// 	for(int i = 0; i <= n; i++)
// 	    cout<<dp[i]<<" ";
// 	   cout<<endl;
	return dp[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends