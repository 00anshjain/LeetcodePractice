// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[], int n, int k) 
    { 
        int prefix[n];
        int mx = 0;
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i-1];
            // if(prefix[i] == k)
            //     mx = max(mx, i+1);
        }
        unordered_map<int, int> mp;
        // prefix[0] = 0;
        for(int i = 0; i < n; i++)
        {
            int sumReqd = prefix[i] - k;
            if(prefix[i] == k)
            {
                mx = max(mx, i+1);
            }
            else if(mp.find(sumReqd) != mp.end())
            {
                mx = max(mx, i - mp[sumReqd]);
            }
            if(mp.find(prefix[i]) == mp.end())
            {
                mp[prefix[i]] = i;
            }
        }
        return mx;
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