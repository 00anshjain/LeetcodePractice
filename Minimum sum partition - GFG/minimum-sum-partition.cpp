// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = accumulate(arr, arr+n, 0);
	    int t = sum/2;
	    bool dp[n+1][t+1];
	    memset(dp, false, sizeof(dp));
	    for(int i = 0; i <= n; i++)
	        dp[i][0] = true;
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= t; j++)
	        {
	            if(j >= arr[i-1])
	                dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    while(!dp[n][t])
	        t--;
	    return sum - t - t;
	    
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends