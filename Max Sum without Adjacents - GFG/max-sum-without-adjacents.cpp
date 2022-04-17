// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int mx2 = 0;//arr[0];
	    int mx1 = 0;//arr[1];
	    for(int i = 0; i< n; i++)
	    {
	        int temp = mx1;
	        mx1 = max(mx2+arr[i], mx1);
	        mx2 = temp;
	    }
	   // int dp[n];
	   // if(n>= 1)
	   //     dp[0] = arr[0];
	   //if(n>=2)
	   //     dp[1] = arr[1];
	   //if(n>= 3)
	   //{
	   //    int i = 2;
	   //    while(i < n)
	   //    {
	   //         dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
	   //         i++;
	   //    }
	   //}
	   return max(mx1, mx2);
	    // code here
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends