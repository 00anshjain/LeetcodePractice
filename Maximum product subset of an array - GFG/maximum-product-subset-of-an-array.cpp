// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    typedef long long ll;
    int mod = 1e9+7;
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here
        ll ans = 1;
        // priority_queue<int, vector<int>, greater<int>> p1;
        ll mxEle = INT_MIN;
        ll neg = INT_MIN;
        // bool hasZero = false;
        bool hasOne = false;
        for(auto x : a)
        {
            if(x == 0)
            {
                // hasZero = true;
                continue;
            }
            ans *= x;
            ans %= mod;
            if(x < 0 && x > neg)
                neg = x;
            if(x == 1)
                hasOne = true;
        }
        if(ans > 0 && ans != 1)
            return ans;
        else if(ans < 0 && a.size() > 1)
            ans /= neg;
        if(ans == 1)
        {
            if(hasOne)
                return ans;
            else
                return 0;
        }
        return ans;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends