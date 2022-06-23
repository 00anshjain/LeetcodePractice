// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    typedef long long ll;
    ll maxMin(int arr[], vector<vector<int>> &dp, int i, int j)
    {
        if(i > j)
            return 0l;
        if(dp[i][j] != -1)
            return dp[i][j];
        ll pro1 = arr[i] + min(maxMin(arr, dp, i+2, j), maxMin(arr, dp, i+1, j-1));
        ll pro2 = arr[j] + min(maxMin(arr, dp, i+1, j-1), maxMin(arr, dp, i, j-2));
        return dp[i][j] = max(pro1, pro2);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return maxMin(arr, dp,  0, n-1);
        // Your code here
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends