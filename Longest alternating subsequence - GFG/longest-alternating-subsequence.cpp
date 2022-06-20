// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int mn = 1, mx = 1;
		    int n = nums.size();
		    if(n < 1)
                return 0;
		    for(int i = 1; i < n; i++)
		    {
		        if(nums[i] > nums[i-1])
		        {
		            mx = mn + 1;
		        }
		        else if(nums[i] < nums[i-1])
		            mn = mx + 1;
		    }
		    return max(mn, mx);
		    // Code here
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends