// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int Sum = accumulate(arr, arr+n, 0);
	    int sum  = (Sum + 1)/2;
	    bool dp[n+1][sum+1];
	    memset(dp, false, sizeof(dp));
	    for(int i = 0; i <= n; i++)
	    {
	        dp[i][0] = true;
	    }
	   // for(int i = 1; i <= sum; i++)
	   // {
	   //     dp[0][i] = false;
	   // }
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= sum; j++)
	        {
	            dp[i][j] = dp[i-1][j];
	            if(j >= arr[i-1])
	            {
	                dp[i][j] |= dp[i-1][j-arr[i-1]];
	            }
	           // else
	               // dp[]
	           // cout<<dp[i][j]<<" ";
	        }
	       // cout<<endl;
	    }
	    
	    int j;
	    for(j = sum; j >= 0; j--)
	    {
	        if(dp[n][j])
                break;
	    }
	   // cout<<j<<endl;
	    return abs(j - (Sum - j));
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends