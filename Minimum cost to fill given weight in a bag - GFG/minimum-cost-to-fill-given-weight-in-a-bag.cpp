// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int recur(int n, vector<vector<int>> &dp, int cost[], int W)
	{
	    if(W == 0)
	        return 0;
	    if(n == 0)
	        return INT_MAX;
	    if(dp[n][W] != -1)
	            return dp[n][W];
	    int k1 = recur(n-1, dp, cost, W);
	    int k2 = INT_MAX;
	    if(n <= W && cost[n-1] != -1)
	    {
	        k2 = recur(n, dp, cost, W - n);
	        if(k2 != INT_MAX)
	            k2 += cost[n-1];
	    }
	    return dp[n][W] = min(k1, k2);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
	    vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
	    int k = recur(N, dp, cost, W);
	    return k == INT_MAX ? -1 : k;
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
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends