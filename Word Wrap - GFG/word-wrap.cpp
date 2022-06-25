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
        if(i >= n)
            return INT_MAX;
        if(dp[i] != -1)
            return dp[i];
        int cost1, cost2;
        int j = k;  //remaining_space
        int ans = INT_MAX;
        int start = i;
        while(i < n)
        {
            if(i == start && nums[i] <= j)
                j -= nums[i];
            else if(nums[i] + 1 <= j)
                j-= (nums[i]+1);
            else
                break;
            cost1 = j*j;
            cost2 = recur(i+1, nums, k, dp);
            ans = min(ans, cost1 + cost2);
            i++;
        }
        if(i == n)
            return dp[start] = 0;
        else
            return dp[start] = ans;
        
        // int j = 0;
        // int j = k;
        // // while(i < n && nums[i] <= k-j)
        // while(i < n && nums[i] <= j)
        // {
        //     // if(nums[i].size() > k-j)
        //     //     break;
        //     // j += nums[i];
        //     j -= nums[i];
        //     if(i < n-1)
        //         a = min(a, recur(i+1, nums, k, dp) + j*j);
        //         // a = min(a, recur(i+1, nums, k, dp) + (k-j)*(k-j));
        //     else
        //     {
        //         a = 0;
        //         break;
        //     }
        //     cout<<a<<" "<<i<<" "<<k-j<<endl;
                
        //     j--;
        //     i++;
            
        // }
        // return dp[i] = a;
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