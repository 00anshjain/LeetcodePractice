// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr, arr+N);
        // int mask = 0;
        int sum = 0;
        for(int j = N-1; j>= 0; j--)
        {
            if(arr[j] == -1)
                continue;
            for(int i = j-1; i>= 0; i--)
            {
                if(arr[i] != -1 && arr[j] - arr[i] < K)
                {
                
                    sum += arr[j];
                    sum += arr[i];
                    arr[i] = -1;
                    break;
                }
            }
        }
        return sum;
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