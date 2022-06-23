// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	typedef long long ll;
	long long dp[4][3][26];
// 	int phone[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
	bool isSafe(int r, int c)
	{
	    if( r < 0 || c < 0 || r >= 4 || c>= 3 || (r == 3 && (c == 0 || c == 2)))
	        return false;
	    return true;
	}
	int xDir[5] = {0, 0, 1, -1, 0};
	int yDir[5] = {1, -1, 0, 0, 0};
	ll DFS(int row, int col, int N)
	{
	    if(!isSafe(row, col))
	        return 0;
	    if(N == 0)
	        return 1;
	    if(dp[row][col][N] != -1)
	        return dp[row][col][N];
	    ll ans = 0l;
	    for(int i = 0; i < 5; i++)
	    {
	        ans += DFS(row + yDir[i], col + xDir[i], N-1);
	    }
	    return dp[row][col][N] = ans;
	}
	long long getCount(int N)
	{
	    N--;
	    memset(dp, -1, sizeof(dp));
	    ll ans = 0l;
	    for(int row = 0; row < 4; row++)
	    {
	        for(int col = 0; col < 3; col++)
	        {
	            ans += DFS(row, col, N);
	        }
	    }
	   // for(int i = 0; i < 4; i++)
	   // {
	   //     for(int j = 0; j < 3; j++)
	   //         cout<<dp[i][j][1]<<" ";
	   //     cout<<endl;
	   // }
	    return ans;
	
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends