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
	    bool dp[2][t+1];
	    memset(dp, false, sizeof(dp));
	   // for(int i = 0; i <= n; i++)
	        dp[0][0] = true;
	        dp[1][0] = true;
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= t; j++)
	        {
	            if(j >= arr[i-1])
	                dp[i%2][j] = (dp[(i-1)%2][j] || dp[(i-1)%2][j-arr[i-1]]);
	            else
	                dp[i%2][j] = dp[(i-1)%2][j];
	        }
	    }
	    while(!dp[n%2][t])
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