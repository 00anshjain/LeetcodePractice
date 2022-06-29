// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i <= k-1; i++)
            pq.push(arr[i]);
        int i = 0;
        vector<int> ans;
        for(int j = k; j < n; j++)
        {
            pq.push(arr[j]);
            // arr[i++] = pq.top();
            ans.push_back(pq.top());
            pq.pop();
        }
        while(!pq.empty())
        {   
            // arr[i++] = pq.top();
            ans.push_back(pq.top());
            pq.pop();
        }
        // return arr;
        // vector<int> ans(arr, arr+n);
        return ans;
        // Your code here
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends