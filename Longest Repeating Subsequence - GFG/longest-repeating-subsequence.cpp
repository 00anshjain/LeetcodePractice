// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	   // int LCS(string &s, int i, int j, vector<vector<int>> &dp)
	   // {
	   //     if(i == 0 || j == 0)
	   //         return 0;
	   //     if(dp[i][j] != -1)
	   //         return dp[i][j];
	   //     if(i == j)
	   //         return dp[i][j] = LCS(s, i-1, j, dp);
	   //     if(s[i-1] == s[j-1])
	   //     {
	   //         return dp[i][j] = 1 + LCS(s, i-1, j-1, dp);
	   //     }
	   //     return dp[i][j] = max(LCS(s, i-1, j, dp), LCS(s, i, j-1, dp));
	   // }
		int LongestRepeatingSubsequence(string s){
		    int n = s.size();
		    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
		    for(int i = 1; i <= n; i++)
		    {
		        for(int j = 1; j <= n; j++)
		        {
		            if(i == j)
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		            else if(s[i-1] == s[j-1])
		                dp[i][j] = 1 + dp[i-1][j-1];
		            else
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		        }
		    }
		    return dp[n][n];
		  //  return LCS(s, n, n-1, dp);
		    
		    // Code here
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends