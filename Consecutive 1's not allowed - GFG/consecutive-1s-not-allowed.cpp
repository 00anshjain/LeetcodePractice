// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int mod = 1e9+7;
	ll countStrings(int n) {
	    ll prev0 = 1l;  //ending with 0
	    ll prev1 = 1l;  //ending with 1
	    for(int i = 2; i <= n; i++)
	    {
	        ll curr0 = (prev0 + prev1)%mod;
	        ll curr1 = (prev0)%mod;
	        prev0 = curr0;
	        prev1 = curr1;
	    }
        return (prev0 + prev1)%mod;
       
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends