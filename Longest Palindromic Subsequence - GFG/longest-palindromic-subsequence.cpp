// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        int n = s.size();
        // int dp[n][n];
        vector<vector<int>> dp(n, vector<int>(n, 1));
        // memset(dp, 1, sizeof(dp);
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
        }
        for(int i = n-3; i >= 0; i--)
        {
            for(int j = i+2; j < n; j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
        //code here
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends