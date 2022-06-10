// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int arr[], int sum, int n){
        // int n = arr.size();
        int dp[n+1][sum+1];
        
        // vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        for(int i = 1; i < sum+1; i++)
            dp[0][i] = false;
        for(int i = 0; i < n+1; i++)
            dp[i][0] = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j >= arr[i-1])
                {
                    dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
        // return subsetSum(arr, n, sum, dp);
        // code here 
    }
    int equalPartition(int n, int arr[])
    {
        int sum = accumulate(arr, arr+n, 0);
        if(sum % 2 == 1)
            return false;
        return isSubsetSum(arr, sum/2, n);
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
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends