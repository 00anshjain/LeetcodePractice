// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod = 1e9+7;
    typedef long long ll;
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here
        ll ans = 1;
        // priority_queue<int, vector<int>, greater<int>> p1;
        int negCount = 0, zeroCount = 0;
        ll neg = INT_MIN;
        // bool hasZero = false;
        for(long long x : a)
        {
            if(x == 0)
            {
                zeroCount++;
                continue;
            }
            ans *= x;
            ans %= mod;
            if(x < 0)
            {
                negCount++;
                if(x > neg)
                    neg = x;
            }
        }
        if(zeroCount == n)
            return 0;
        if(n == 1)
            return ans;
        if(ans < 0)
        {
            if(negCount == 1 && negCount + zeroCount == n)
                return 0;
            ans /= neg;
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