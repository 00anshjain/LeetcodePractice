// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int arr[])
    {
        // int dp[n];
        vector<int> dp(n, 1);
        // memset(dp, 1,sizeof(dp));
        dp[n-1] = 1;
        int mx = 1;
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = i+1; j < n; j++)
            {
                if(abs(arr[j] - arr[i]) == 1)
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends