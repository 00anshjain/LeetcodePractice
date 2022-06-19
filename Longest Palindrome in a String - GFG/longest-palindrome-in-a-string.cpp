// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int end = 0, start = 0;
        for(int i = 0; i < n-1; i++)
        {
            dp[i][i] = true;
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                if(end - start + 1 < 2)
                {
                    start = i;
                    end = i+1;
                }
            }
        }
        dp[n-1][n-1] = 1;
        for(int i = n-3; i>= 0; i--)
        {
            for(int j = i+2; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    if(dp[i+1][j-1] > 0)
                    {
                        dp[i][j] = dp[i+1][j-1];
                        if(dp[i][j])
                        {
                            if(end - start < j - i)
                            {
                                start = i;
                                end = j;
                            }
                            else if((end - start == j - i) && i < start)
                            {
                                start = i;
                                end = j;
                            }
                            // {
                            //     if(s.substr(start, end - start + 1) > s.substr(start, j - i + 1))
                            //     {
                            //         start = i;
                            //         end = j;
                            //     }
                            // }
                        }
                    }
                    
                }
            }
        }
        return s.substr(start, end - start + 1);
        // code here
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends