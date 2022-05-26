// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    {
        int sum = 0, res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum - k == 0 || mp.find(sum - k) != mp.end())
            {
                if(sum - k == 0)
                {
                    res = max(res, i+1);
                }
                else
                {
                    res = max(res, i - mp[sum-k]);
                }
            }
            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
        return res;
        // Complete the function
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends