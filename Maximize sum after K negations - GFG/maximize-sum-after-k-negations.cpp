// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        sort(arr, arr+n);
        int i = 0;
        while(i < n && k > 0 && arr[i] < 0)
        {
            k--;
            arr[i] *= -1;
            i++;
        }
        int mnidx;
        // if(i == n)
        //     i == n-1;
        if(k > 0 && k%2 == 1)
        {
            if(i == n)
                mnidx = n-1;
            if(arr[i] == 0)
                mnidx = i;
            else if(arr[i] > 0 && i == 0)
                mnidx = i;
            else
            {
                if(arr[i-1] > arr[i])
                    mnidx = i;
                else
                    mnidx = i-1;
            }
            arr[mnidx] *= -1;
        }
        return accumulate(arr, arr+n, 0);
        // Your code goes here
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends