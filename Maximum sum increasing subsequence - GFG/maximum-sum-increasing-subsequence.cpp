// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int recur(int j, int dp[], int arr[])
	{
	    int ans = 0;
	    if(dp[j] != -1)
	        return dp[j];
	    for(int i = j-1; i >= 0; i--)
	    {
	        if(arr[i] < arr[j])
	        {
	            ans = max(ans, recur(i, dp, arr));
	        }
	    }
	    ans += arr[j];
	    return dp[j] = ans;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    memset(dp, -1, sizeof(dp));
	    int mx = 0;
	    for(int i = 0; i < n; i++)
	    {
	        mx = max(recur(i, dp, arr), mx);
	    }
	    return mx;
	    // Your code goes here
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends