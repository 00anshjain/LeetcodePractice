// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findWinner(int n, int x, int y)
	{
	    bool dp[n+1];
	    dp[0] = false;
	    dp[1] = true;
	    for(int i = 2; i <= n; i++)
	    {
	        dp[i] = false;
	        if(dp[i-1] == false)
	        {
	            dp[i] = true;
	            continue;
	        }
	        if(i - x >= 0 && dp[i-x] == false)
	        {
	            dp[i] = true;
	            continue;
	        }
	        if(i - y >= 0 && dp[i-y] == false)
	        {
	            dp[i] = true;
	            continue;
	        }
	        
	    }
	    return dp[n];
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
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends