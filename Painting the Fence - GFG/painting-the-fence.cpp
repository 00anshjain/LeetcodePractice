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
    // ll ans = 0;
    // void countWay(int n, int k,int lastColor, int taken)
    // {
    //     // cout<<n<<endl;
    //     if(n == 0)
    //     {
    //         // cout<<ans<<endl;
    //         ans++;
    //         return;
    //     }
    //     for(int i = 0; i < k; i++)
    //     {
    //         if(i == lastColor)
    //         {
    //             if(taken == 2)
    //                 continue;
    //             else
    //                 countWay(n-1, k, lastColor, taken+1);
    //         }
    //         else
    //         {
    //             countWay(n-1, k, i, 1);
    //         }
    //     }
        
    // }
    long long countWays(int n, int k){
        
        if(n == 1)
            return k;
        if(n== 2)
            return k*k;
            
        vector<ll> same(n+1, -1), diff(n+1, -1);
        same[1] = k;
        diff[1] = k;
        diff[2] = k*(k-1);
        same[2] = k;
        for(int i = 3; i <= n; i++)
        {
            // cout<<i<<endl;
            diff[i] = (diff[i-1]*(k-1) + same[i-1]*(k-1))%mod;
            same[i] = diff[i-1];
            // cout<<diff[i] + same[i]<<endl;
        }
        
        return (diff[n] + same[n])%mod;
        
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