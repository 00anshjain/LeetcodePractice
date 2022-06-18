// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalin(string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    int recur(int i, int j, string &str, vector<vector<int>>& dp)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(isPalin(str, i, j))
            return dp[i][j] = 0;
        int ans = INT_MAX;
        for(int k = i; k < j; k++)
        {
            // if(isPalin(str, i, k) && isPalin(str, k+1, j))
            // {
                // ans = min(ans, 1 + recur(i, k, str, dp) + recur(k+1, j, str, dp));
                int temp = 1 + recur(i, k, str, dp) + recur(k+1, j, str, dp);
                if(temp < ans)
                    ans = temp;
            // }
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recur(0, n-1, str, dp);
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends