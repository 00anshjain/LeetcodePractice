// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s)
    {
        int n = s.size();
        int cut[n];
        for(int i = 0; i < n; i++)
            cut[i] = i;
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        for(int j = 0; j < n; j++)  //end at j , start at i
        {
            for(int i = j; i >= 0; i--)
            {
                if(s[i] == s[j] && (j - i + 1 <= 2 || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    if(i != 0)
                        cut[j] = min(cut[j], 1 + cut[i-1]);
                    else
                        cut[j] = 0;
                }
            }
        }
        return cut[n-1];
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