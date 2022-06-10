// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int sum;
    int recur(int arr[], int n, int t, int currSum, vector<vector<int>>& dp)
    {
        // if(currSum == 0)
        //     return sum - t - t;
        if(n == 0 || currSum == 0)
        {
            int k = t - currSum;
            return (sum - k) - k;
        }
        if(dp[n][currSum] != -1)
            return dp[n][currSum];
        if(arr[n-1] <= currSum)
        {
            return dp[n][currSum] = min(recur(arr, n-1, t, currSum - arr[n-1], dp), recur(arr, n-1, t, currSum, dp));
        }
        return dp[n][currSum] = recur(arr, n-1, t, currSum, dp);
        
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    sum = accumulate(arr, arr+n, 0);
	    int t = sum/2;
	   // bool dp[n+1][t+1];
	   vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1, -1));
	   return recur(arr, n, t, t, dp);
	   // while(!dp[n][t])
	   //     t--;
	   // return sum - t - t;
	    
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