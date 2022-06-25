// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int n;
    int recur(int i, vector<int> &nums, int k, vector<int>& dp)
    {
        if(i >= n-1)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int a = INT_MAX;
        int j = k;
        int start = i;
        while(i < n && nums[i] <= j)
        {
            j -= nums[i];
            if(i < n-1)
                a = min(a, recur(i+1, nums, k, dp) + j*j);
            else
                a = 0;
            j--;
            i++;
            
        }
        return dp[start] = a;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        n = nums.size();
        vector<int> dp(n, -1);
        return recur(0, nums, k, dp);
        // Code here
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends