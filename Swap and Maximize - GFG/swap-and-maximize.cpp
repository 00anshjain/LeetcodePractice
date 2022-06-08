// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends

typedef long long ll;
long long int maxSum(int arr[], int n)
{
    sort(arr, arr+n);
    vector<int> v1(arr, arr+n/2);
    vector<int> v2(arr+n/2, arr+n);
    reverse(v2.begin(), v2.end());
    ll sum = 0;
    for(int i = 0; i < n/2; i++)
    {
        sum += abs(v1[i]-v2[i]);
        sum += abs(v1[(i+1)%(n/2)] - v2[i]);
    }
    return sum;
    // ll sum = 0;
    // int j = n-1;
    // int i = 1;
    // while(i < j)
    // {
    //     swap(arr[i], arr[j]);
    //     i+= 2;
    //     j--;
    // }
    // for(int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    // for(int i = 1; i < n; i++)
    // {
    //     // cout<<sum<<endl;
    //     sum += abs(arr[i] - arr[i-1]); 
    // }
    // sum += abs(arr[n-1] - arr[0]);
    // return sum;
    
}