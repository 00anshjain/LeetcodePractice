// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
	    vector<vector<int>> dp(N+1, vector<int> (W+1, INT_MAX));
	    dp[0][0] = 0;
	    for(int i = 1; i <= N; i++)
	    {
	        dp[i][0] = 0;
	        for(int j = 1; j <= W; j++)
	        {
	            if(j >= i && cost[i-1] != -1 && dp[i][j-i] != INT_MAX)
	            {
	                dp[i][j] = min(dp[i-1][j], dp[i][j - i] + cost[i-1]);
	            }
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    return dp[N][W] == INT_MAX ? -1 : dp[N][W];
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