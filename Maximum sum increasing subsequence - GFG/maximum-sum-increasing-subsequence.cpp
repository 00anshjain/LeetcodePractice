// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n);
	    dp[n-1] = arr[n-1];
	    for(int i = n-2; i>= 0; i--)
	    {
	       // int x = arr[i];
	       // int mx = arr[i]
	       dp[i] = arr[i];
	        for(int j = i+1; j < n; j++)
	        {
	            if(arr[i] < arr[j])
	            {
	                dp[i] = max(dp[i], arr[i] + dp[j]);
	            }
	        }
	    }
	    return *max_element(dp.begin(), dp.end());
	   // int mx = 0;
	   // for(int i = 0; i < n; i++)
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