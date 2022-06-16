// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    typedef long long ll;
    int mod = 1e9+7;
    long long countWays(int n, int k){
        if(n == 1)
            return k;
        if(n == 2)
            return k*k;
        ll same[n+1], diff[n+1];
        same[1] = (ll)k;
        diff[1] = (ll)k;
        same[2] = (ll)k;
        diff[2] = (ll)k * (k - 1);
        for(int i = 3; i <= n; i++)
        {
            same[i] = diff[i-1];
            diff[i] = ((same[i-1] + diff[i-1])*(k-1))%mod;
        }
        return (same[n]+diff[n])%mod;
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
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends