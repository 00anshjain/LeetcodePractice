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
	    vector<ll> dp(n+1);
        if(n == 0)
            return 1;
        if(n == 1)
            return 2;
        dp[0] = 1l;
        dp[1] = 2l;
        for(int i = 2; i <= n; i++)
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        return dp[n];
        // bool last = false;
        // int j = 1;
        // while(1)
        // {
        //     for(int i = 0; i < j; i++)
        //     {
        //         dp.push_back((2*dp[j] + dp[i]));
        //         // if(dp.back() > n)
        //         // {
        //         //     cout<<"break "<<dp.back()<<" "<<n<<endl;
        //         //     last = true;
        //         //     break;
        //         // }
        //     }
        //     j++;
        //     if(last == true)
        //         break;
        // }
        // // for(auto x : dp)
        // //     cout<<x<<" ";
        // // cout<<endl;
        // return dp.size()-1;
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