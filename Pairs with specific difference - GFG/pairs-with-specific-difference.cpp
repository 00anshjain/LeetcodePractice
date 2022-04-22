// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        priority_queue<int> pq(arr, arr+N);
        int ans = 0;
        while(!pq.empty())
        {
            int t = pq.top();
            pq.pop();
            if(pq.empty())
                break;
            int p = pq.top();
            pq.pop();
            if(t-p < K)
            {
                ans += t;
                ans += p;
            }
            else
                pq.push(p);
        }
        return ans;
        // sort(arr, arr+N, greater<int>());
        // int i = 0, j = 1;
        // while(i < n && j < n)
        // {
        //     if(arr[])
        // }
        // Your code goes here   
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends