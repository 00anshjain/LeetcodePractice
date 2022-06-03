// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> arr(nums.begin(), nums.end());
	    sort(arr.begin(), arr.end());
	    unordered_map<int, int> mp;
	    int cnt = 0, n = nums.size();
	    for(int i = 0; i < n; i++)
	    {
	        mp[arr[i]] = i;
	    }
	    for(int i = 0; i < n; i++)
	    {
	        while(arr[i] != nums[i])
	        {
	            swap(nums[i], nums[mp[nums[i]]]);
	            cnt++;
	        }
	       // if(nums[i] != arr[i])
	       // {
	       //     cnt++;
	       //    // int to_be_here = arr[i];
	       //     int idx = find(nums.begin()+i, nums.end(), arr[i]) - nums.begin();
	       //     swap(nums[i], nums[idx]);
	       // }
	    }
	    return cnt;
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
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends